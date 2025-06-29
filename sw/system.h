/******************************************************************************/
/* ARCHIVO:     system.h                                                      */
/* AUTOR:       Federico Ramos                                                */
/* DESCRIPCIÓN: -                                                             */
/* ÚLT. MODIF:  13-06-2019 1632                                               */
/* COMENTARIO:  -                                                             */
/******************************************************************************/


#ifndef __SYSTEM_H
#define __SYSTEM_H


/******************************************************************************/
/* PUERTOS: DEFINICION DE CONSTANTES                                          */
/******************************************************************************/
#define ALL_INPUT 0xFF
#define INPUT 1
#define OUTPUT 0


/******************************************************************************/
/* PUERTOS: DEFINICION DE PINES UTILIZADOS  (ÚNICO PARA CADA PROYECTO)        */
/******************************************************************************/
#define BUZZER      PORTAbits.RA0
#define LCD_BL        PORTAbits.RA1
#define VBAT        PORTAbits.RA2
#define HUMIDITY_SEN      PORTAbits.RA3
#define UNUSED_RA4  PORTAbits.RA4
#define BCD_EN      PORTAbits.RA5
#define SW4  PORTAbits.RA6

#define SW2    PORTBbits.RB0
#define LCD_DAT4    PORTBbits.RB1
#define SW3    PORTBbits.RB2
#define LCD_RW    PORTBbits.RB3
#define LCD_RS    PORTBbits.RB4
#define LCD_EN    PORTBbits.RB5
#define LCD_DAT5    PORTBbits.RB6
#define LCD_DAT7    PORTBbits.RB7

#define SW5         PORTCbits.RC0
#define SW8         PORTCbits.RC1
#define TEMP_SEN     PORTCbits.RC2
//PORTCbits.RC3 no existe
#define SWXXXX1       PORTCbits.RC4
#define SW0       PORTCbits.RC5
#define BUS_CS1     PORTCbits.RC6
#define PWM     PORTCbits.RC7

#define SW6   PORTDbits.RD0
#define SW7     PORTDbits.RD1
#define BUS_DATA    PORTDbits.RD2
#define BUS_CS0     PORTDbits.RD3
#define VIRTUAL_GND       PORTDbits.RD4
#define SW1       PORTDbits.RD5
#define RF_D1       PORTDbits.RD6
#define LCD_DAT6       PORTDbits.RD7

#define BCD2        PORTEbits.RE0
#define BCD1        PORTEbits.RE1
#define BRD_DP      PORTEbits.RE2
#define UNUSED_RE3  PORTEbits.RE3

/******************************************************************************/
/* PUERTOS: DEFINICION DE DATA DIRECTION REGISTERS                            */
/******************************************************************************/
#define DDR_BUZZER         TRISA0
#define DDR_LCD_BL        TRISA1
#define DDR_VBAT        TRISA2
#define DDR_HUMIDITY_SENS      TRISA3
#define DDR_UNUSED_RA4  TRISA4
#define DDR_BCD_EN      TRISA5
#define DDR_SW4  TRISA6

#define DDR_SW2    TRISB0
#define DDR_LCD_DAT4    TRISB1
#define DDR_SW3    TRISB2
#define DDR_LCD_RW    TRISB3
#define DDR_LCD_RS    TRISB4
#define DDR_LCD_EN    TRISB5
#define DDR_LCD_DAT5    TRISB6
#define DDR_LCD_DAT7    TRISB7

#define DDR_SW5         TRISC0
#define DDR_SW8         TRISC1
#define DDR_TEMP_SENS     TRISC2
//TRISC3 no existe
//#define DDR_SW1       TRISC4
//TRISC3 no existe ---> ONLY INPUT
#define DDR_SW0       TRISC5
//TRISC3 no existe ---> ONLY INPUT

#define DDR_BUS_CS1     TRISC6
#define DDR_PWM     TRISC7

#define DDR_SW6   TRISD0
#define DDR_SW7     TRISD1
#define DDR_BUS_DATA    TRISD2
#define DDR_BUS_CS0     TRISD3
#define DDR_VIRTUAL_GND       TRISD4
#define DDR_SW1       TRISD5
#define DDR_RF_D1       TRISD6
#define DDR_LCD_DAT6       TRISD7

#define DDR_BCD2        TRISE0
#define DDR_BCD1        TRISE1
#define DDR_BRD_DP      TRISE2
//TRISE3 no existe


/******************************************************************************/
/* DEFINICION DE MACROS                                                       */
/******************************************************************************/

/* MACRO:       INIT_DDR()                                                    */
/* PARÁMETROS:  -                                                             */
/* DEVUELVE:    -                                                             */
/* DESCRIPCIÓN: -                                                             */
/* ÚLT. MODIF:  -                                                             */
/* COMENTARIO:  -                                                             */
#define INIT_DDR() {                    \
                   DDR_BUZZER=OUTPUT;   \
DDR_LCD_RS=OUTPUT;   \
DDR_LCD_RW=OUTPUT;   \
DDR_LCD_EN=OUTPUT;   \
DDR_LCD_DAT4=OUTPUT;   \
DDR_LCD_DAT5=OUTPUT;   \
DDR_LCD_DAT6=OUTPUT;   \
DDR_LCD_DAT7=OUTPUT;   \
DDR_SW0=INPUT;   \
DDR_SW1=INPUT;   \
DDR_SW2=INPUT;   \
DDR_SW3=INPUT;   \
DDR_LCD_BL=OUTPUT;\
DDR_VIRTUAL_GND=OUTPUT;\
DDR_PWM=OUTPUT;\
                   }   


/* MACRO:       INIT_PORTS()                                                  */
/* PARÁMETROS:  -                                                             */
/* DEVUELVE:    -                                                             */
/* DESCRIPCIÓN: -                                                             */
/* ÚLT. MODIF:  -                                                             */
/* COMENTARIO:  -                                                             */
#define INIT_PORTS() {              \
            BUZZER=0;\
                     }


/******************************************************************************/
/* DECLARACION DE FUNCIONES                                                   */
/******************************************************************************/
void systemInit(void);


#endif