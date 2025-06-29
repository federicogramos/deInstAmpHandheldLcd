/******************************************************************************/
/* ARCHIVO:     interrupts.c                                                  */
/* AUTOR:       Federico Ramos                                                */
/* DESCRIPCIÓN: Proyecto PFP_DRV_LED_STK_MAIN                                 */
/* ÚLT. MODIF:  10-06-2019 1632                                               */
/* COMENTARIO:  Siempre en directorio del proyecto, cada proyecto tiene       */
/*              interrupciones distintas.                                     */
/******************************************************************************/


/******************************************************************************/
/* ARCHIVOS DE ENCABEZAMIENTO UTILIZADOS                                      */
/******************************************************************************/
#include <projectHeader.h>
#include <thisProject.h>
#include <interrupts.h>
#include <system.h>
#include <mainDefinitions.h>
#include <pulsadorPinFast_1ms_lib.h>
#include <timer_lib.h>
#include <lcd_lib.h>
#include <pwm_sw_lib.h>
#include <encoder_lib.h>
#include <adc18f_lib.h>


/******************************************************************************/
/* FUNCIÓN:     isr0(void)                                                    */
/* PARÁMETROS:  -                                                             */
/* DEVUELVE:    -                                                             */
/* DESCRIPCIÓN: -                                                             */
/* ÚLT. MODIF:  -                                                             */
/* COMENTARIO:                                                                */
/******************************************************************************/
void interrupt isr0(void)
	{
	//if(INTCONbits.TMR0IE && INTCONbits.TMR0IF) isr_timer0_hi_priority();
	if(IRQ_TIMER1) isr_timer1_low_priority();
    if(IRQ_TIMER3) isr_timer3_low_priority();
    if(IRQ_ADC) isr_adc();

	}





//*******************************************************************************
//
//*******************************************************************************

void isr_timer1_low_priority(void)//HANDHELD=1MS
	{
	TMR1=IRQ_TIMER1_RESET_VAL;// Reseteo contador de la interrupción.

	timerDriver(TMR_LCD);
    timerDriver(TMR_1S);
    timerDriver(TMR_BUZZER);

    lcdFsmParser(); //Si no lo pongo como interrupcion, el scanf, cuando solicita ingreso al usuario, se queda esperando pero nunca veria el usuario reflejado sus ingresos cuando hace ingreso de numeros con varias cifras.




    if(ENCODER_CW_ID(E0) && pwm.tonResetVal<999)
        {
        pwm.tonResetVal++;
        lcdSettings.display_refresh=1;
        BUZZER=1;
        TMR_START(TMR_BUZZER);
        }
    if(ENCODER_CCW_ID(E0) && pwm.tonResetVal>0)
        {
        pwm.tonResetVal--;
        lcdSettings.display_refresh=1;
        BUZZER=1;
        TMR_START(TMR_BUZZER);
        }

    if(TMR_TIMEOUT(TMR_BUZZER)) BUZZER=0;




    ENCODER_0_DRIVER();





    puls_dc_driver(P0N,FLANCO_N,PORTCbits.RC5);
    puls_dc_driver(P1N,FLANCO_N,PORTDbits.RD5);
    puls_dc_driver(P2N,FLANCO_N,PORTBbits.RB0);
    puls_dc_driver(P3N,FLANCO_N,PORTBbits.RB5);

    puls_dc_driver(P4N,FLANCO_N,PORTAbits.RA6);
    puls_dc_driver(P5N,FLANCO_N,PORTCbits.RC0);

    puls_dc_driver(P8N,FLANCO_N,PORTCbits.RC1);





	PIR1bits.TMR1IF=0;
	}


/******************************************************************************/
/* FUNCIÓN:     void isr_timer3_low_priority(void)                            */
/******************************************************************************/
char aux;
void isr_timer3_low_priority(void)//HANDHELD=100us
    {
	TMR3=IRQ_TIMER3_RESET_VAL;// Reseteo contador de la interrupción.
   


//if(PWM==1) PWM=0;
//else PWM=1;


	pwm_sw_driver();

	TMR3IF=0;
	}

