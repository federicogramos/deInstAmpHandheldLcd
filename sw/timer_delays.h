//******************************************************************************
// ARCHIVO: timer_delays.h
//******************************************************************************


#ifndef __TIMER_DELAYS_H
#define __TIMER_DELAYS_H


//******************************************************************************
// DEFINICION DE TIEMPOS POR PARTE DEL USUARIO
//******************************************************************************
type_timerDelayConstant timerDelayConstant[CANT_TIMERS]=
    {
    50,//TMR_LCD
    200,//TMR_FIXED_1S
    30,//TMR_FIXED_BUZZER
    };


#endif//__TIMER_DELAYS_H