/********************************************************************
 Project: OperatingSystem
 File:    OsBackgroundTask.c
 Created: 09/03/2022
 Author:  Leon Ablinger / AblL
 *******************************************************************/

#include <string.h>
#include <stdlib.h>
#include "OsBackgroundTask.h"
#include "HTLStddef.h"


/******** Definition of global variables********/

static TBgtListHeader BgList;

void
OSBackgroundTaskInit( void )
{
	memset( &BgList, 0, sizeof(BgList)); // allocate and set to 0

}

TBool
OSBackgroundTaskAddTask( TBgFunction	aFunction,
						 void *			aUserData)
{
// Function to add task to background task list
	TBgElement bgElement;
	TBgElement nextElement;
	bgElement = calloc ( sizeof( * bgElement), 1);
	// return if element could not be created
	if ( ! bgElement )
		return EFALSE;
	
	if (  ! BgList.First ) // list is empty
	{
		BgList.First = bgElement; // set new element as first element
		BgList.ExecuteNext = bgElement;
		bgElement->Function = aFunction;
		bgElement->UserData = aUserData;
		BgList.Size += 1;
		return ETRUE;
	}
		
	nextElement = BgList.First;
	while (nextElement->Next != NULL) // Search for last element in list
		nextElement = nextElement->Next;
			
	nextElement->Next = bgElement; // set last element in list
	
	bgElement->Function = aFunction;
	bgElement->UserData = aUserData;
	BgList.Size += 1;
	return ETRUE;
}

TBool
OSBackgroundTaskRemove(  TBgFunction	aFunction,
						 void *			aUserData )
{
	if (!BgList.First) // If first element is false -> list doesn't exist
		return EFALSE;
		
	TBgElement nextElement = BgList.First;
	TBgElement lastElement = BgList.First;

	while(nextElement != NULL) // If end of list is reached
	{
		if (nextElement->Function == aFunction && nextElement->UserData == aUserData)
		{
			if (BgList.ExecuteNext == nextElement)
				BgList.ExecuteNext = nextElement->Next;
				
			if (nextElement == BgList.First)
			{
				BgList.First = nextElement->Next;
				if(BgList.Size == 1)
					BgList.First = NULL;
			} 
			else
				lastElement->Next = nextElement->Next;
				
			free(nextElement); // Delete element
			BgList.Size -= 1;
			return ETRUE;
		}
		lastElement = nextElement;
		nextElement = nextElement->Next;
	}
	return EFALSE;
}

void
OSBackgroundTaskExecute( void )
{
// Function to start the next background task
	if ( !BgList.ExecuteNext )
		BgList.ExecuteNext = BgList.First;
		
	if ( BgList.ExecuteNext )
	{
		BgList.ExecuteNext->Function(BgList.ExecuteNext->UserData);
		BgList.ExecuteNext = BgList.ExecuteNext->Next;
	}
		
}

