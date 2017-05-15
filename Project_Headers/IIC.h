/*
 * IIC.h
 *
 *  Created on: Mar 4, 2017
 *      Author: manuel
 */

#ifndef IIC_H_
#define IIC_H_

/*************************************************************************************************/
/*********************                 Includes                **********************/
/*************************************************************************************************/
#include "derivative.h" /* include peripheral declarations */
#include "types.h"

/*************************************************************************************************/
/*********************                 Defines                    **********************/
/*************************************************************************************************/

/* Driver configuration. The user should modify these values */
#define SCL PTBD_PTBD0
#define SDA PTBD_PTBD1

/* These should not be modified by the user */
#define controlByteMPU 	0b11010000
#define controlByteMag  0b00111100

/*************************************************************************************************/
/*********************                 Typedefs                **********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************            Functions Like Macros              **********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************              Extern Variables              **********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************                  Extern Constants                    **********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************              Function Prototypes              **********************/
/*************************************************************************************************/

/*!*-----------------------------------------------------------------------------------------------
* \name     SCI_InitTx
* \brief    Configures the Baud Rate and enables the transmission
* \param    void
* \return   void
-------------------------------------------------------------------------------------------------*/
void IIC_Init (void);
void IIC_start_bit (void);
void IIC_stop_bit (void);
void IIC_send_byte (unsigned char);
unsigned char IIC_ACK_Input (void);
void IIC_byte_write(u8, u8, unsigned char);
unsigned char IIC_random_read(u8,unsigned char);
unsigned char IIC_read_byte (void);
void IIC_ACK_output (unsigned char);
/*************************************************************************************************/



#endif /* IIC_H_ */
