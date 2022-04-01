/********************************************************************
 Project: OperatingSystem
 File:    OsTimerTask.h
 Created: 09/03/2022
 Author:  Leon Ablinger / AblL
 *******************************************************************/

#ifndef OSTIMERTASK_H
#define OSTIMERTASK_H

typedef void (*TTimerTaskFunction)(void * aUserData, unsigned long aTimerTicks);

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

#endif