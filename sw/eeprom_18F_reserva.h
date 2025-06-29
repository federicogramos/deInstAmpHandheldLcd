/******************************************************************************/
/* ARCHIVO:     eeprom_18f_reserva.h                                          */
/* AUTOR:       Federico Ramos                                                */
/* DESCRIPCIÓN: -                                                             */
/* ÚLT. MODIF:  27-06-2019 1834                                               */
/* COMENTARIO:  -                                                             */
/******************************************************************************/


#ifndef __EEPROM_18F_RESERVA_H
#define __EEPROM_18F_RESERVA_H


/******************************************************************************/
/* RESERVA                                                                    */
/******************************************************************************/
__EEPROM_DATA   (
            	0x00,//EEADDR_QUEMUESTRO_MEM
            	0x02,//EEADDR_EEADDR_NOUTPUTS_MEM
            	0x00,//EEADDR_EEADDR_OPTION_MEM
            	0x0A,//EEADDR_EEADDR_BRILLO_TON_MEM
            	0x00,//EEADDR_
            	0x00,//EEADDR_
            	0x00,//EEADDR_
            	0x00 //EEADDR_
            	);


/******************************************************************************/
/* FIN DE ARCHIVO                                                             */
/******************************************************************************/
#endif// __EEPROM_18F_RESERVA_H