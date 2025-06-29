//****************************************************************************
// ARCHIVO: main.c
// AUTOR: Federico Ramos
// ÚLT. MODIF:  30-08-2022
//****************************************************************************


//****************************************************************************
// ARCHIVOS DE ENCABEZAMIENTO UTILIZADOS
//****************************************************************************
#include <projectHeader.h>
#include <thisProject.h>//Funciones específicas de cada proyecto
#include <main.h>//Fuses y otras cosas.
#include <system.h>//Inicialización del sistema.
#include <pulsadorPinFast_1ms_lib.h>
#include <timer_lib.h>
#include <eeprom_18f_lib.h>
#include <lcd_lib.h>
#include <fsm_lib.h>
#include <pwm_sw_lib.h>
#include <encoder_lib.h>
#include <adc18f_lib.h>




int adcResult;
//****************************************************************************
// FUNCION: main()
//****************************************************************************
void main(void)
	{
    systemInit();
    adcSetup_18F46K80();

    thisProjectInit();
    
    lcdFsmInit();
    TMR_INIT_LOOP(TMR_1S);

    VIRTUAL_GND=0;
    pwm_sw_init();

//LCD_BL=1;

    ADC_START(ADC_V_BAT);

    while(1)
        {

        thisProject_driver();


        if(TMR_TIMEOUT(TMR_1S))
            {
            adcDriver();

            if(ADC_NEW_RESULT(ADC_V_BAT))
                {
                adcResult=getConv();
                ADC_START(ADC_V_BAT);
                }


            lcdFile.flg&=~_READ;//ya no es de lectura
            lcdFile.flg|=_WRITE;//es de escritura
            
            rewind(&lcdFile);
            fprintf(&lcdFile,(char*)".......!");
            fputc('\n',&lcdFile);
            fprintf(&lcdFile,(char*)"YYYY_YY!");
    
            rewind(&lcdFile);
            fprintf(&lcdFile,(char*)"%i",pwm.tonResetVal);

            fseek(&lcdFile,LCD_LENGTH,SEEK_CUR);
            //fprintf(&lcdFile,(char*)"%i",(int)(adcResult*1.15));//MUESTRA VINPUT ADC
            fprintf(&lcdFile,(char*)"%i",(int)(adcResult*0.3555));//MUESTRA VBAT
            //fseek(&lcdFile,,SEEK_CUR);
    

            lcdFile.flg&=~_WRITE;//ya no es de escritura
            lcdFile.flg|=_READ;//es de lectura
            }



        }
    }

