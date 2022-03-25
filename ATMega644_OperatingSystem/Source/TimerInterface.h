/********************************************************************
 Project: OperatingSystem
 File:    TimerInterface.h
 Created: 09/03/2022
 Author:  Leon Ablinger / AblL
 *******************************************************************/

#ifndef TIMERINTERFACE_H
#define TIMERINTERFACE_H

#include "HTLStddef.h"

typedef void (*TTimerFunction)(void *aUserData);
typedef TBool (*TTimerInit)(TTimerInitParams);
typedef void (*TTimerSetInterruptFunction)(TTimerFunction aFunction, void *aUserData);
typedef void (*TTimerStart)(void);
typedef void (*TTimerStop)(void);

typedef struct
{
	unsigned long CpuClk;
	unsigned long Resolution;
} TTimerInitParams;

typedef struct
{
	TTimerInit					Init;
	TTimerSetInterruptFunction	SetInterruptFunction;
	TTimerStart					Start;
	TTimerStop					Stop;
} TTimerInterface;

#endif