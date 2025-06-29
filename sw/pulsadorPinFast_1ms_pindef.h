//*****************************************************************************
// ARCHIVO: pulsadorPinFast_1ms_pindef.h
// AUTOR: Federico Ramos
// ULT. MODIF: 15-08-2022
//*****************************************************************************

#ifndef __PULSADOR_PIN_FAST_1MS_PINDEF_H
#define __PULSADOR_PIN_FAST_1MS_PINDEF_H


//*****************************************************************************
// CONSTANTES DE FUNCIONAMIENTO DE LIBRERÍA
//10->INTERRUPCIÓN 1MS
//100->INTERRUPCIÓN 100US
#define PULS_PIN_N_ANTIREBOTE 100//LE PONGO EN ESTE PROYECTO 10MS PORQUE DE ESA MANERA CON ANTIREBOTE, LA FRECUENCIA MAXIMA ES 50HZ, ALGO ACEPTABLE
//*****************************************************************************


//*****************************************************************************
// SETEAR PUERTOS UTILIZADOS COMO PULSADORES
// 15-08-2022 ESTO ESTA CONFIGURADO PARA PROYECTO "DE_HANDHELD"
volatile bit PULSADOR_0 @ ((unsigned)&PORTC*8)+5;
volatile bit PULSADOR_1 @ ((unsigned)&PORTD*8)+5;
volatile bit PULSADOR_2 @ ((unsigned)&PORTB*8)+0;
volatile bit PULSADOR_3 @ ((unsigned)&PORTB*8)+5;

volatile bit PULSADOR_4 @ ((unsigned)&PORTA*8)+6;
volatile bit PULSADOR_5 @ ((unsigned)&PORTC*8)+0;

volatile bit PULSADOR_6 @ ((unsigned)&PORTD*8)+0;
volatile bit PULSADOR_7 @ ((unsigned)&PORTD*8)+1;
volatile bit PULSADOR_8 @ ((unsigned)&PORTC*8)+1;
//*****************************************************************************


//*****************************************************************************
// SETER FLANCOS PARA CADA PULSADOR
//#define FLANCO_P0 FLANCO_N
//#define FLANCO_P1 FLANCO_N
//#define FLANCO_P2 FLANCO_N
//#define FLANCO_P3 FLANCO_N
//#define FLANCO_P4 FLANCO_N
//#define FLANCO_P5 FLANCO_N
//*****************************************************************************


//*****************************************************************************
// COMPLETAR ESTRUCTURA PRINCIPAL
// LA CANTIDAD DE ELEMENTOS CORRESPONDE A LA CANTIDAD DE PULSADORES
// {state,prevState,timer}
t_pulsPin pulsPin[PULS_PIN_CANT]=
	{
	{1,1,0},
    {1,1,0},
	{1,1,0},
	{1,1,0},
	{1,1,0},
	{1,1,0},
	{1,1,0},
	{1,1,0}
    };
//*****************************************************************************


#endif//__PULSADOR_PIN_FAST_1MS_PINDEF_H
