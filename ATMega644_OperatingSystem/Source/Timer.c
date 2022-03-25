/********************************************************************
 Project: OperatingSystem
 File:    Timer.c
 Created: 09/03/2022
 Author:  Leon Ablinger / AblL
 *******************************************************************/

#include <string.h>
#include <stdio.h>
#include "HTLStddef.h"
#include "TimerInterface.h"

typedef struct
{
	TTimerInterface Interface;
	TTimerInitParams Params;
} TTimer;

static TTimer Timer;

void TimerSetInterface(TTimerInterface aInterface)
{
	memset(&Timer, 0, sizeof(TTimer));
	
	Timer.Interface = aInterface;
}

TBool TimerInit(TTimerInitParams aParams)
{
	if (Timer.Interface.Init)
	{
		Timer.Params = aParams;
		return Timer.Interface.Init(aParams);
	}
	
	return EFALSE;
}

void TimerGetInfo(char* aString)
{
	sprintf(aString, "Clock: %lu, Interval: %lu", Timer.Params.CpuClk, Timer.Params.Resolution);
}

void TimerStart(void)
{
	if (Timer.Interface.Start)
		Timer.Interface.Start();
}

void TimerStop(void)
{
	if (Timer.Interface.Stop)
	Timer.Interface.Stop();
}