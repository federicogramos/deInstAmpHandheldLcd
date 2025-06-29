/**************7****************************************************************/
/* ARCHIVO:     system.c                                                      */
/* AUTOR:       Federico Ramos                                                */
/* DESCRIPCIÓN: -                                                             */
/* ÚLT. MODIF:  13-06-2019 0034                                               */
/* COMENTARIO:  Cada proyecto particular tiene su propio archivo "system.c".  */
/******************************************************************************/


/******************************************************************************/
/* ARCHIVOS DE ENCABEZAMIENTO UTILIZADOS                                      */
/******************************************************************************/
#include <projectHeader.h>
#include <system.h>
#include <interrupts.h>
//#include <adc_lib.h>


/******************************************************************************/
/* FUNCIÓN:     systemInit(void)                                              */
/* PARÁMETROS:  -                                                             */
/* DEVUELVE:    -                                                             */
/* DESCRIPCIÓN: -                                                             */
/* ÚLT. MODIF:  -                                                             */
/* COMENTARIO:                                                                */
/******************************************************************************/
void systemInit(void)
    {
    // IRCF[2..0]=000=>8Mhz HF-INTOSC/2 output frequency is used (8 MHz, default)
    // 4xPLL => 32MHZ (Fosc)
    PLLEN=1;
    OSCCONbits.SCS=0x00; //System Clock = Primary oscillator
    //   UCFGbits.UTRDIS=1;//necesario para poder usar RC4/5 como digital input
    
    RCONbits.IPEN=1;//low priority interrupts enable
    
    INTCON2bits.RBPU=0;// pull ups portb=0 (enabled)
    WPUB=0xFF;//ACTIVO PULL UPS INDIVIDUALES EN PORTB (TODOS)
    PADCFG1bits.RDPU=1;// pull ups portd=1 (enabled)
    
    
    
    
    IPR2bits.TMR3IP=0;//interrupt timer 3 es low priority
    //IPR1bits.ADIP=0;//int AD low priority
    IPR1bits.TMR1IP=0;//LOW PRIORITY
    
    //ADCON1bits.PCFG=0x0F;//para que todos los pines sean digitales y poder leer sus estados digitales.
    


    //adcSetup();
    
    //IRQ_TIMER0_SETUP();
    IRQ_TIMER1_SETUP();
    IRQ_TIMER3_SETUP();

    
    INIT_DDR();// Establece los puertos de entrada/salida.
    INIT_PORTS();// Al arranque, pone en un estado conocido a las salidas.
    
    //INTCONbits.TMR0IE=1;
    PIE1bits.TMR1IE=1;
    PIE2bits.TMR3IE=1;
    
    
    // CCP1
    // IPR1bits.CCP1IP=0;//interrupt timer 3 es low priority
    //PIE1bits.CCP1IE=1;
    
    //CCP1CON
    
    
    
    INTCONbits.PEIE=1;
    INTCONbits.GIE=1;
    INTCONbits.GIEH=1;
    INTCONbits.GIEL=1;
    }

