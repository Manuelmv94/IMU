/*
 * IMU.h
 *
 *  Created on: Mar 4, 2017
 *      Author: manuel
 */

#ifndef IMU_H_
#define IMU_H_

/*************************************************************************************************/
/*********************                 Includes                **********************/
/*************************************************************************************************/

#include "derivative.h" /* include peripheral declarations */
#include "types.h"
#include "IIC.h"


/*************************************************************************************************/
/*********************              Function Prototypes              **********************/
/*************************************************************************************************/

void IMU_Init(void);
void IMU_Accelerometer_UpdateValues(void);
void IMU_Gyroscope_UpdateValues(void);
void IMU_Magnetometer_UpdateValues(void);
void IMU_Temperature_UpdateValues(void);
i16 IMU_Accelerometer_get_X_Value(void);
i16 IMU_Accelerometer_get_Y_Value(void);
i16 IMU_Accelerometer_get_Z_Value(void);

/*************************************************************************************************/

#endif /* IMU_H_ */
