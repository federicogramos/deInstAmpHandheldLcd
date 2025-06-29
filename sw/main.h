/******************************************************************************/
/* ARCHIVO:     main.h                                                        */
/* AUTOR:       Federico Ramos                                                */
/* DESCRIPCIÓN: -                                                             */
/* ÚLT. MODIF:  10-06-2019 1632                                               */
/* COMENTARIO:  -                                                             */
/******************************************************************************/
#ifndef __MAIN_H
#define __MAIN_H


/******************************************************************************/
/* COMPILE-TIME DIRECTIVES                                                    */
/******************************************************************************/
#pragma config XINST=OFF//SIN EXTENDED INSTRUCTION SET

#pragma config FOSC=INTIO2
#pragma config PLLCFG=ON//For the INTIOx modes (HF-INTOSC). Only the PLLEN can enable the PLL (PLLCFG is ignored)




/* FGR: En el voltimetro 20cm ocurria que al tener BORV=3 (2.05V)             */
/* aparentemente, al apagar la alimentacion, habia suficiente tiempo para un  */
/* funcionamiento erratico escribiendo la EEPROM (en la variable que          */
/* controlaba al brillo del cartel).                                          */
/* Cambiando a BORV=1 (4.33V) deja de ocurrir.                                */

#pragma config BOREN=ON
#pragma config BORPWR=LOW//CONSUMO VS EXACTITUD DEL BOR
#pragma config BORV=0

#pragma config PWRTEN=ON

#pragma config WDTEN=OFF

//#pragma config PBADEN=OFF
//#pragma config LPT1OSC=OFF

#pragma config MCLRE=OFF
//#pragma config MCLRE=ON

//#pragma config DEBUG=OFF
#pragma config STVREN=OFF
//#pragma config LVP=OFF

#pragma config CP0=ON
#pragma config CP1=ON
#pragma config CP2=ON
#pragma config CP3=ON

#pragma config CPD=ON
#pragma config CPB=ON

#pragma config WRT0=ON
#pragma config WRT1=ON
#pragma config WRT2=ON
#pragma config WRT3=ON

#pragma config WRTB=ON
#pragma config WRTC=ON
//#pragma config WRTD=OFF

#pragma config EBTR0=1
#pragma config EBTR1=1
#pragma config EBTR2=1
#pragma config EBTR3=1

#pragma config EBTRB=1

#pragma config IDLOC0=0
#pragma config IDLOC1=0
#pragma config IDLOC2=0
#pragma config IDLOC3=0
#pragma config IDLOC4=0
#pragma config IDLOC5=0
#pragma config IDLOC6=0
#pragma config IDLOC7=0


/******************************************************************************/
/* FIN DE ARCHIVO                                                             */
/******************************************************************************/
#endif//__MAIN_H