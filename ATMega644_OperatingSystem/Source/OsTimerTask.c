/********************************************************************
 Project: OperatingSystem
 File:    OsTimerTask.c
 Created: 09/03/2022
 Author:  Leon Ablinger / AblL
 *******************************************************************/

#include <string.h>
#include <stdlib.h>
#include "HTLStddef.h"
#include "OsTimerTask.h"

TBool OsTimerTaskInit(
	unsigned long aCpuClk,
	unsigned long aTimerInterval
);

TBool OsTimerTaskAddTask(
	TTimerTaskFunction aFunction,
	void *			   aUserData
);

TBool OsTimerTaskRemoveTask(
	TTimerTaskFunction aFunction,
	void *			   aUserData
);
	
void OsTimerTaskStart(void);

void OsTimerTaskStop(void);