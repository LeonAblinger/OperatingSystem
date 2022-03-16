/********************************************************************
 Project: OperatingSystem
 File:    Os.c
 Created: 09/03/2022
 Author:  Leon Ablinger / AblL
 *******************************************************************/

#include <avr/io.h>
#include "Os.h"
#include "OsBackgroundTask.h"

TBool
OSInit(void)
{
	OSBackgroundTaskInit();	
	
	return ETRUE;
}

