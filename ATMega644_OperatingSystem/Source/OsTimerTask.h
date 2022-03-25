/********************************************************************
 Project: OperatingSystem
 File:    OsTimerTask.h
 Created: 09/03/2022
 Author:  Leon Ablinger / AblL
 *******************************************************************/

#ifndef OSTIMERTASK_H
#define OSTIMERTASK_H

typedef void (*TTimerTaskFunction)(void * aUserData, unsigned long aTimerTicks);

#endif