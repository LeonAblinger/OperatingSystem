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

OsTimerTaskInit(
	unsigned long aCpuClk,
	unsigned long aTimerInterval
	);
	
OsTimerTaskAddTask();
OsTimerTaskRemoveTask();
	
OsTimerTaskStart();
OsTimerTaskStop();