/********************************************************************
 Project: OperatingSystem
 File:    Timer.h
 Created: 09/03/2022
 Author:  Leon Ablinger / AblL
 *******************************************************************/

#ifndef TIMER_H
#define TIMER_H

#include "HTLStddef.h"
#include "TimerInterface.h"

typedef struct
{
	TTimerInterface Interface;
	TTimerInitParams Params;
} TTimer;

void TimerSetInterface(TTimerInterface aInterface);

TBool TimerInit(TTimerInitParams aParams);

void TimerGetInfo(char* aString);

void TimerStart(void);

void TimerStop(void);

#endif