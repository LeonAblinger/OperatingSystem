/********************************************************************
 Project: OperatingSystem
 File:    TestOperatingSystem.c
 Created: 09/03/2022
 Author:  Leon Ablinger / AblL
 *******************************************************************/

#include <avr/io.h>
#include "Os.h"

void TestBgTask1(void);

void TestTask1(void * UserData);

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

void TestTask1(void * aUserData){
	TUserData1 * UserData = ( TUserData1 * ) aUserData;
	
	UserData->Counter++;
}

void TestBgTask1(void)
{
	OsInit();
	
	TUserData1 UserData1;
	UserData1.Counter = 0;
	TUserData1 UserData2;
	UserData2.Counter = 0;
	TUserData1 UserData3;
	UserData3.Counter = 0;
	
	OSBackgroundTaskAddTask( TestTask1, &UserData1 );
	OSBackgroundTaskAddTask( TestTask1, &UserData2 );
	OSBackgroundTaskAddTask( TestTask1, &UserData3 );

	
	while ( 1 )
	{
		OSBackgroundTaskExecute();
		
		/*
		if(UserData1.Counter == 1) // delete first
		{
			OSBackgroundTaskRemove(TestTask1, &UserData1);
			UserData1.Counter++;
		}
		
		if(UserData2.Counter == 2) //delete second
		{
			OSBackgroundTaskRemove(TestTask1, &UserData2);
			UserData2.Counter++;
		}
		
		if(UserData3.Counter == 3) // delete third
		{
			OSBackgroundTaskRemove(TestTask1, &UserData3);
			UserData3.Counter++;
		}
		*/
	}
}
