/******************************************************************************/
/* ARCHIVO:     thisProjectMacros.h                                           */
/* AUTOR:       Federico Ramos                                                */
/* DESCRIPCI�N: Proyecto PFP_DRV_LED_STK_MAIN                                 */
/* �LT. MODIF:  04-07-2019 00:10                                              */
/* COMENTARIO:  -                                                             */
/******************************************************************************/


#ifndef __THIS_PROJECT_MACROS_H
#define __THIS_PROJECT_MACROS_H


/******************************************************************************/
/* FUNCI�N:     MACRO_CUANDO_APRIETAN_BOTON_OPTION()                          */
/* PAR�METROS:  -                                                             */
/* DESCRIPCI�N: -                                                             */
/* �LT. MODIF:  -                                                             */
/* COMENTARIO:                                                                */
/******************************************************************************/
# define MACRO_CUANDO_APRIETAN_BOTON_OPTION()                                  \
    if(PULSPIN_EVENT_ID_FN(OPTION_FN))                                         \
        {                                                                      \
        if(auxOptionCounter==OPTION_COUNTER_VAL_REPOSO                         \
           || ++auxOptionCounter>OPTION_MAX) auxOptionCounter=0;               \
        showOnBoardDisplay(auxOptionCounter,TMR_SHOW_ONBOARD_DISPLAY_EXTENDED);\
                                                                               \
        if(BIT_GETVAL_QUICK(pfp_drv_led_stk.option,auxOptionCounter)) BRD_DP=1;\
        else BRD_DP=0;                                                         \
        }


/******************************************************************************/
/* FUNCI�N:     MACRO_CUANDO_APRIETAN_BOTON_MUXLENGTH()                       */
/* PAR�METROS:  -                                                             */
/* DESCRIPCI�N: -                                                             */
/* �LT. MODIF:  -                                                             */
/* COMENTARIO:                                                                */
/******************************************************************************/
////FGR: MUXLENGTH TIENE 2 FUNCIONES
//PRIMERO SETEAR MUXLENGTH
//FGR: SEGUNDA FUNCION QUE CUMPLE: SETEO BITS OPCIONES                   
# define MACRO_CUANDO_APRIETAN_BOTON_MUXLENGTH()                                      \
    if(PULSPIN_EVENT_ID_FN(MUXLENGTH_FN))                                             \
        {                                                                             \
        if(auxOptionCounter==OPTION_COUNTER_VAL_REPOSO)                               \
            {                                                                         \
    		if(++pfp_drv_led_stk.muxLength>MUXLENGTH_MAX) pfp_drv_led_stk.muxLength=1;\
            EEPROM_WRITE_CHAR(EEADDR_MUXLENGTH_MEM,pfp_drv_led_stk.muxLength);        \
            showOnBoardDisplay(pfp_drv_led_stk.muxLength,TMR_SHOW_ONBOARD_DISPLAY);   \
            BRD_DP=0;                                                                 \
            }                                                                         \
        else                                                                          \
            {                                                                         \
            if(BIT_GETVAL_QUICK(pfp_drv_led_stk.option,auxOptionCounter))             \
                {                                                                     \
                BIT_CLR(pfp_drv_led_stk.option,auxOptionCounter);                     \
                BRD_DP=0;                                                             \
                }                                                                     \
            else                                                                      \
                {                                                                     \
                BIT_SET(pfp_drv_led_stk.option,auxOptionCounter);                     \
                BRD_DP=1;                                                             \
                }                                                                     \
    		EEPROM_WRITE_CHAR(EEADDR_OPTION_MEM,pfp_drv_led_stk.option);              \
            TMR_START(TMR_SHOW_ONBOARD_DISPLAY_EXTENDED);                             \
            }                                                                         \
        }


/******************************************************************************/
/* FUNCI�N:     MACRO_CUANDO_APRIETAN_BOTON_NOUTPUTS()                        */
/* PAR�METROS:  -                                                             */
/* DESCRIPCI�N: -                                                             */
/* �LT. MODIF:  -                                                             */
/* COMENTARIO:                                                                */
/******************************************************************************/
//MACRO_REFRESH_N_MODULOS SE INVOCA PORQUE NMODULOS = F(NOUTPUTS)
# define MACRO_CUANDO_APRIETAN_BOTON_NOUTPUTS()                                      \
    if(PULSPIN_EVENT_ID_FN(NOUTPUTS_FN))                                             \
        {                                                                            \
        if(++pfp_drv_led_stk.nOutputs>NOUTPUTS_MAX) pfp_drv_led_stk.nOutputs=1;      \
		EEPROM_WRITE_CHAR(EEADDR_NOUTPUTS_MEM,pfp_drv_led_stk.nOutputs);             \
        MACRO_REFRESH_N_MODULOS()                                                    \
                                                                                     \
        if(pfp_drv_led_stk.nOutputs<10)                                              \
            {                                                                        \
            showOnBoardDisplay(pfp_drv_led_stk.nOutputs,TMR_SHOW_ONBOARD_DISPLAY);   \
            BRD_DP=0;                                                                \
            }                                                                        \
        else                                                                         \
            {                                                                        \
            showOnBoardDisplay(pfp_drv_led_stk.nOutputs-10,TMR_SHOW_ONBOARD_DISPLAY);\
            BRD_DP=1;                                                                \
            }                                                                        \
        }


/******************************************************************************/
/* FUNCI�N:     MACRO_CUANDO_TIMEOUT_ONBOARD_DISPLAY_TIMER()                  */
/* PAR�METROS:  -                                                             */
/* DESCRIPCI�N: -                                                             */
/* �LT. MODIF:  -                                                             */
/* COMENTARIO:                                                                
//        FGR: TMR_SHOW_ONBOARD_DISPLAY_XXX TIMEOUT RELACIONADO CON showOnBoardDisplay(digit,timer) PORQUE ES �STA QUIEN
//        DISPARA EL TIMER, PARA APAGARLO AQU� UNA VEZ TRANSCURRIDO EL TIEMPO.
/******************************************************************************/
//FGR: EN REPOSO, SIEMPRE INDICANDO PARA VISUALIZAR LED PLACA ENCHUFADA
# define MACRO_CUANDO_TIMEOUT_ONBOARD_DISPLAY_TIMER()                          \
	if(TMR_TIMEOUT(TMR_SHOW_ONBOARD_DISPLAY)                                   \
       || TMR_TIMEOUT(TMR_SHOW_ONBOARD_DISPLAY_EXTENDED))                      \
        {                                                                      \
        BCD_EN=0;                                                              \
        BRD_DP=1;                                                              \
        auxOptionCounter=OPTION_COUNTER_VAL_REPOSO;                            \
        }                                                                      \


/******************************************************************************/
/* FUNCI�N:     MACRO_CUANDO_APRIETAN_CTRL_REMOTO_A()                  */
/* PAR�METROS:  -                                                             */
/* DESCRIPCI�N: -                                                             */
/* �LT. MODIF:  -                                                             */
/* COMENTARIO:                                                                */
/******************************************************************************/
//CONTROL REMOTO
# define MACRO_CUANDO_APRIETAN_CTRL_REMOTO_A()                                 \
    if(PULSPIN_EVENT_ID_FN(CTRL_A))                                            \
        {                                                                      \
        showOnBoardDisplay(0,TMR_SHOW_ONBOARD_DISPLAY);                        \
        BRD_DP=0;                                                              \
        }                                                                      \


/******************************************************************************/
/* FUNCI�N:     MACRO_CUANDO_APRIETAN_CTRL_REMOTO_B()                         */
/* PAR�METROS:  -                                                             */
/* DESCRIPCI�N: -                                                             */
/* �LT. MODIF:  -                                                             */
/* COMENTARIO:                                                                */
/******************************************************************************/
//CONTROL REMOTO
# define MACRO_CUANDO_APRIETAN_CTRL_REMOTO_B()                                 \
    if(PULSPIN_EVENT_ID_FN(CTRL_B))                                            \
        {                                                                      \
        showOnBoardDisplay(1,TMR_SHOW_ONBOARD_DISPLAY);                        \
        BRD_DP=0;                                                              \
        }                                                                      \


/******************************************************************************/
/* FUNCI�N:     MACRO_CUANDO_APRIETAN_CTRL_REMOTO_C()                  */
/* PAR�METROS:  -                                                             */
/* DESCRIPCI�N: -                                                             */
/* �LT. MODIF:  -                                                             */
/* COMENTARIO:                                                                */
/******************************************************************************/
//CONTROL REMOTO
# define MACRO_CUANDO_APRIETAN_CTRL_REMOTO_C()                                 \
    if(PULSPIN_EVENT_ID_FN(CTRL_C))                                            \
        {                                                                      \
        showOnBoardDisplay(2,TMR_SHOW_ONBOARD_DISPLAY);                        \
        BRD_DP=0;                                                              \
        }                                                                      \


/******************************************************************************/
/* FUNCI�N:     MACRO_CUANDO_APRIETAN_CTRL_REMOTO_D()                         */
/* PAR�METROS:  -                                                             */
/* DESCRIPCI�N: -                                                             */
/* �LT. MODIF:  -                                                             */
/* COMENTARIO:                                                                */
/******************************************************************************/
//CONTROL REMOTO
# define MACRO_CUANDO_APRIETAN_CTRL_REMOTO_D()                                 \
    if(PULSPIN_EVENT_ID_FN(CTRL_D))                                            \
        {                                                                      \
        showOnBoardDisplay(3,TMR_SHOW_ONBOARD_DISPLAY);                        \
        BRD_DP=0;                                                              \
        }                                                                      \


/******************************************************************************/
/* FIN DE ARCHIVO                                                             */
/******************************************************************************/
#endif//__THIS_PROJECT_MACROS_H