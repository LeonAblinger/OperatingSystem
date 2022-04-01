/********************************************************************
 Project: OperatingSystem
 File:    TestOperatingSystem.c
 Created: 09/03/2022
 Author:  Leon Ablinger / AblL
 *******************************************************************/

#include <avr/io.h>
#include "Os.h"
#include "OsBackgroundTask.h"

void TestBgTask1(void);

void TestTask(void * UserData);

int main(void)
{
    while (1) 
    {
		TestBgTask1();
    }
}

typedef struct 
{
	unsigned int Counter;
} TUserData1;

void TestTask(void * aUserData){
	TUserData1 * UserData = ( TUserData1 * ) aUserData;
	
	UserData->Counter++;
}

void TestBgTask1(void)
{
	OSInit();

	TUserData1 UserData1;
	UserData1.Counter = 0;
	TUserData1 UserData2;
	UserData2.Counter = 0;
	TUserData1 UserData3;
	UserData3.Counter = 0;
	
	// Simple functionality test
	{
		OSBackgroundTaskAddTask(TestTask, &UserData1 );
		OSBackgroundTaskAddTask(TestTask, &UserData2 );
		OSBackgroundTaskAddTask(TestTask, &UserData3 );

		while ( 1 )
		{
			OSBackgroundTaskExecute();
		
			if (UserData1.Counter == 5) OSBackgroundTaskRemove(TestTask, &UserData1);
		
			if (UserData2.Counter == 7) OSBackgroundTaskRemove(TestTask, &UserData2);
		
			if (UserData3.Counter == 9) 
			{
				OSBackgroundTaskRemove(TestTask, &UserData3);
				break;
			}
		}
	}
	
	// Advanced memory test
	{
		int i, loop;
		
		while ( 1 )
		{
			for (loop = 0; loop < 100; loop++)
			{
				OSBackgroundTaskAddTask(TestTask, &UserData1);
				OSBackgroundTaskAddTask(TestTask, &UserData2);
				OSBackgroundTaskAddTask(TestTask, &UserData3);
				
				for  (i = 0; i < 9; i++) OSBackgroundTaskExecute();
				OSBackgroundTaskRemove(TestTask, &UserData1);
				for  (i = 0; i < 9; i++) OSBackgroundTaskExecute();
				OSBackgroundTaskRemove(TestTask, &UserData2);
				for  (i = 0; i < 9; i++) OSBackgroundTaskExecute();
				OSBackgroundTaskRemove(TestTask, &UserData3);
				for  (i = 0; i < 3; i++) OSBackgroundTaskExecute();
			}
		}
	}
}
