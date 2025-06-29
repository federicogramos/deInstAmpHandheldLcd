/******************************************************************************/
/* ARCHIVO:     thisProject.c                                                 */
/* AUTOR:       Federico Ramos                                                */
/* DESCRIPCIÓN: Proyecto PFP_DRV_LED_STK_MAIN                                 */
/* ÚLT. MODIF:  10-06-2019 1632                                               */
/* COMENTARIO:  Cada proyecto particular tiene su propio "thisProject.c".     */
/******************************************************************************/


/******************************************************************************/
/* ARCHIVOS DE ENCABEZAMIENTO INDISPENSABLES                                  */
/******************************************************************************/
#include <projectHeader.h>
#include <thisProject.h>


/******************************************************************************/
/* ARCHIVOS DE ENCABEZAMIENTO USADOS EN ESTE PROYECTO EN PARTICULAR           */
/******************************************************************************/
#include <system.h>
#include <eeprom_18f_lib.h>
#include <interrupts.h>
//#include <timer_lib.h>
#include <pulsadorPinFast_1ms_lib.h>
//#include <disp7seg_lib.h>//FGR: en thisProject, se usa una macro aquí definida


/******************************************************************************/
/* DECLARACION DE VARIABLES USADAS EN EL PROYECTO                             */
/******************************************************************************/
t_handheld handheld;

/******************************************************************************/
/* FUNCIÓN:     thisProjectInit()                                             */
/* PARÁMETROS:  -                                                             */
/* DEVUELVE:    -                                                             */
/* DESCRIPCIÓN: -                                                             */
/* ÚLT. MODIF:  -                                                             */
/* COMENTARIO:                                                                */
/******************************************************************************/
void thisProjectInit(void)
    {
    handheld.pwmIncEncoder=1;//VALOR QUE SUMA CADA VEZ QUE GIRA ENCODER
    //EEPROM_READ_CHAR(EEADDR_OPTION_MEM,pfp_drv_led_stk.option);	
    //EEPROM_READ_CHAR(EEADDR_MUXLENGTH_MEM,pfp_drv_led_stk.muxLength);
    //EEPROM_READ_CHAR(EEADDR_NOUTPUTS_MEM,pfp_drv_led_stk.nOutputs);
	//EEPROM_READ_CHAR(EEADDR_BRILLO_TON_MEM,disp_sys.tOn);//tOn equivale a los ticks que enciende los displays en la interrupción

	//TMR_INIT_LOOP(TMR_250MS);

    //disp7seg_ini();
    }


/******************************************************************************/
/* FUNCIÓN:     thisProject_driver(void)                                      */
/* PARÁMETROS:  -                                                             */
/* DEVUELVE:    -                                                             */
/* DESCRIPCIÓN: -                                                             */
/* ÚLT. MODIF:  -                                                             */
/* COMENTARIO:                                                                */
/******************************************************************************/
//char aux;
void thisProject_driver(void)
    {
    
    }


/******************************************************************************/
/* FUNCIÓN:     thisProject_get_event()                                       */
/* PARÁMETROS:  -                                                             */
/* DEVUELVE:    -                                                             */
/* DESCRIPCIÓN: -                                                             */
/* ÚLT. MODIF:  -                                                             */
/* COMENTARIO:                                                                */
/******************************************************************************/
void thisProject_get_event(void)
    {
    }


/******************************************************************************/
/* FUNCIÓN:     updateOnBoardDisplay(char digit)                              */
/* RECIBE:      char digit                                                    */
/* DEVUELVE:    -                                                             */
/* DESCRIPCIÓN:                                                               */
/*              Agarra char digit (que contiene un número  que se desea)      */
/*              mostrar en el display 7 segmentos onBoard y setea las         */
/*              señales de salida que correspondan para actualizar el estado. */
/* ÚLT. MODIF:  27-06-2019 12:41                                              */
/* COMENTARIO:                                                                */
/******************************************************************************/
void showOnBoardDisplay(char digit,char timer)
    {

    }