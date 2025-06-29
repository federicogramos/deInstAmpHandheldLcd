//*****************************************************************************
// ARCHIVO: encoder_pindef.h
// AUTOR: Federico Ramos
// ULT. MODIF: 08-09-2022
//*****************************************************************************

#ifndef __ENCODER_PINDEF_H
#define __ENCODER_PINDEF_H


//*****************************************************************************
// CONSTANTES DE FUNCIONAMIENTO DE LIBRERÍA
//10->INTERRUPCIÓN 1MS
//100->INTERRUPCIÓN 100US
//#define ENCODER_N_ANTIREBOTE 1//LE PONGO EN ESTE PROYECTO 10MS PORQUE DE ESA MANERA CON ANTIREBOTE, LA FRECUENCIA MAXIMA ES 50HZ, ALGO ACEPTABLE
//*****************************************************************************


//*****************************************************************************
// SETEAR PUERTOS UTILIZADOS COMO PULSADORES
// 15-08-2022 ESTO ESTA CONFIGURADO PARA PROYECTO "DE_HANDHELD"
//volatile bit ENCODER_0A @ ((unsigned)&PORTD*8)+0;
//volatile bit ENCODER_0B @ ((unsigned)&PORTD*8)+1;
//*****************************************************************************


//*****************************************************************************
// COMPLETAR ESTRUCTURA PRINCIPAL
// LA CANTIDAD DE ELEMENTOS CORRESPONDE A LA CANTIDAD DE PULSADORES
// {state,prevState,timer}
t_encoder encoder[ENCODER_CANT]=
	{
	{0}
    };
//*****************************************************************************


#endif//__ENCODER_PINDEF_H
