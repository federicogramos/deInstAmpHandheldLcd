/******************************************************************************/
/* ARCHIVO:     interrupts.c                                                  */
/* AUTOR:       Federico Ramos                                                */
/* DESCRIPCIÓN: Proyecto PFP_DRV_LED_STK_MAIN                                 */
/* ÚLT. MODIF:  10-06-2019 1632                                               */
/* COMENTARIO:  Siempre en directorio del proyecto, cada proyecto tiene       */
/*              interrupciones distintas.                                     */
/******************************************************************************/


/******************************************************************************/
/* PUERTOS: DEFINICION DE CONSTANTES                                          */
/******************************************************************************/
#define IRQ_TIMER0_RESET_VAL 210
//241

// Se setea el tiempo de interrupción en 2.5ms (oscilador=20Mhz,
// timer0 prescaler=64). Calculo a realizar:
// n=256-(Tinterrupt[s])*(fclk[Hz]/[4*prescaler])=256-(3.125E-3)*(48E6/[4*8])


//PROYECTO HANDHELD 2022-08-27
//TMR1 INTERRUPT ON OVERFLOW:
// Se setea el tiempo de interrupción en 25ms (oscilador=32Mhz,
// timer1 prescaler=4). Calculo a realizar:
// n=65536-(Tinterrupt[s])*(fclk[Hz]/[4*prescaler])=65536-(25E-3)*(32E6/[4*4])=15536
//#define IRQ_TIMER1_RESET_VAL 0UL
//#define IRQ_TIMER1_RESET_VAL 15536UL//25ms
//#define IRQ_TIMER1_RESET_VAL 45536UL//10ms
#define IRQ_TIMER1_RESET_VAL 653536UL//1ms

#define IRQ_TIMER3_RESET_VAL 64736UL
//#define IRQ_TIMER3_RESET_VAL 57536UL
//#define IRQ_TIMER3_RESET_VAL 15536UL
//#define IRQ_TIMER3_RESET_VAL 5536UL
//#define IRQ_TIMER3_RESET_VAL 65436UL
// Importantísimo: es indispensable especificar que el número es UL (unsigned
// long), porque de otro modo, el compilador lo pierde en el camino, y cuando
// lo quiero asignar, solamente asigna un byte, y el resto cero.
// Se setea el tiempo de interrupción en 250ms (oscilador interno=20Mhz,
// timer1 con prescaler=8). Calculo a realizar:
// n=65536-(Tinterrupt[s])*(fclk[Hz]/[4*prescaler])
// n=65536-25E-3*(48E6/[4*8])=28036

#define IRQ_TIMER2_RESET_VAL 255




/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#define IRQ_ENABLE()  {GIE=1;}
#define IRQ_DISABLE() {GIE=0;}

#define IRQ_PERIPHERAL_ENABLE()  {PEIE=1;}
#define IRQ_PERIPHERAL_DISABLE() {PEIE=0;}
// Peripheral interrupts: timer1, comparator, AD, EEPROM write complete.
   



// Esta función, asigna un valor al acumulador del timer0.
// If TMR0 is written, the increment is inhibited for the following two
// instruction cycles. The user can work around this by writing an adjusted
// value to the TMR0 register.

#define IRQ_TIMER1_SET(value) {                      \
                              TMR1L=LOW_BYTE(value); \
                              TMR1H=HIGH_BYTE(value);\
                              }



// Esta función, asigna un valor al acumulador del timer0.
// If TMR0 is written, the increment is inhibited for the following two
// instruction cycles. The user can work around this by writing an adjusted
// value to the TMR0 register.



#define IRQ_TIMER0_SETUP() {                                    \
                           T0CONbits.T08BIT=1;              \
                           T0CONbits.T0CS=0;                       \
                           T0CONbits.PSA=0;                               \
                           T0CONbits.T0PS=0x07;                          \
                           TMR0=IRQ_TIMER0_RESET_VAL;\
                           T0CONbits.TMR0ON=1;           \
                           }



// SOURCE = FOSC/4
#define IRQ_TIMER1_SETUP() {                                    \
                           T1CONbits.TMR1CS0=0; 	\
							T1CONbits.TMR1CS1=0; 	\
                           T1CONbits.T1CKPS0=0;   	\
							T1CONbits.T1CKPS1=1;   	\
                           T1CONbits.NOT_T1SYNC=1;  	\
                           TMR1=IRQ_TIMER1_RESET_VAL;	\
                           T1CONbits.TMR1ON=1;  	\
                           }


#define IRQ_TIMER3_SETUP()\
    {\
    T3CONbits.TMR3CS0=0;\
    T3CONbits.TMR3CS1=0;\
    T3CONbits.T3CKPS0=0;\
    T3CONbits.T3CKPS1=0;\
    T3CONbits.NOT_T3SYNC=1;\
    TMR3=IRQ_TIMER3_RESET_VAL;\
    T3CONbits.TMR3ON=1;\
    }


#define IRQ_TIMER3_SETUP_____() {                                    \
                           T3CONbits.TMR3CS=0;                            \
                           T3CONbits.T3CKPS=0x03;                          \
                           T3CONbits.T3SYNC=1;                            \
                           TMR3=IRQ_TIMER3_RESET_VAL;         \
                           T3CONbits.TMR3ON=1;                            \
                           T3CONbits.RD16=1;\
                           }


#define IRQ_TIMER0 TMR0IE&&TMR0IF// Timer0 interrupt enable and flag set.
#define IRQ_TIMER1 TMR1IE&&TMR1IF// Timer1 interrupt enable and flag set.
#define IRQ_TIMER2 TMR2IE&&TMR2IF// Timer2 interrupt enable and flag set.
#define IRQ_TIMER3 TMR3IE&&TMR3IF

#define IRQ_CCP1 CCP1IE&&CCP1IF
#define IRQ_CCP2 CCP2IE&&CCP2IF




/******************************************************************************/
/* DECLARACION DE FUNCIONES                                                   */
/******************************************************************************/
void isr_timer0_hi_priority(void);
void isr_timer1_low_priority(void);
void isr_timer3_low_priority(void);
//void isr_timer2_low_priority(void);
