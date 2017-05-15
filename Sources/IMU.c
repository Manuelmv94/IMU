/*
 * IMU.c
 *
 *  Created on: Mar 4, 2017
 *      Author: Javier Barragan
 */

#include "IMU.h"

i16 accelerometer_x_value;
i16 accelerometer_y_value;
i16 accelerometer_z_value;

i16	gyroscope_x_value;
i16	gyroscope_y_value;
i16	gyroscope_z_value;

i16	magnetometer_x_value;
i16	magnetometer_y_value;
i16	magnetometer_z_value;

i16 Temperature;

void IMU_Init()
{
	  IIC_Init();
	  IIC_byte_write(controlByteMPU,0x6B,0);
	  IIC_byte_write(controlByteMPU,0x1C,0);
	  IIC_byte_write(controlByteMPU,0x1B,0);
	  IIC_byte_write(controlByteMag,0x00,0);
	  IIC_byte_write(controlByteMag,0x01,0);
}

void IMU_Accelerometer_UpdateValues()
{
	accelerometer_x_value=IIC_random_read(controlByteMPU,0x3B);
	accelerometer_x_value<<=8;
	accelerometer_x_value|=IIC_random_read(controlByteMPU,0x3C);
	
	accelerometer_y_value=IIC_random_read(controlByteMPU,0x3D);
	accelerometer_y_value<<=8;
	accelerometer_y_value|=IIC_random_read(controlByteMPU,0x3E);
	
	accelerometer_z_value=IIC_random_read(controlByteMPU,0x3F);
	accelerometer_z_value<<=8;
	accelerometer_z_value|=IIC_random_read(controlByteMPU,0x40);	
	
}

void IMU_Gyroscope_UpdateValues()
{
	gyroscope_x_value=IIC_random_read(controlByteMPU,0x43);
	gyroscope_x_value<<=8;
	gyroscope_x_value|=IIC_random_read(controlByteMPU,0x44);
	
	gyroscope_y_value=IIC_random_read(controlByteMPU,0x45);
	gyroscope_y_value<<=8;
	gyroscope_y_value|=IIC_random_read(controlByteMPU,0x46);
	
	gyroscope_z_value=IIC_random_read(controlByteMPU,0x47);
	gyroscope_z_value<<=8;
	gyroscope_z_value|=IIC_random_read(controlByteMPU,0x48);
}

void IMU_Temperature_UpdateValues()
{
	Temperature=IIC_random_read(controlByteMPU,0x41);
	Temperature<<=8;
	Temperature|=IIC_random_read(controlByteMPU,0x42);
}

i16 IMU_Accelerometer_get_X_Value()
{
	return accelerometer_x_value;
}

void IMU_Magnetometer_UpdateValues()
{
	magnetometer_x_value=IIC_random_read(controlByteMag,0x03);
	magnetometer_x_value<<=8;
	magnetometer_x_value|=IIC_random_read(controlByteMag,0x04);
		
	magnetometer_z_value=IIC_random_read(controlByteMag,0x05);
	magnetometer_z_value<<=8;
	magnetometer_z_value|=IIC_random_read(controlByteMag,0x06);
		
	magnetometer_y_value=IIC_random_read(controlByteMag,0x07);
	magnetometer_y_value<<=8;
	magnetometer_y_value|=IIC_random_read(controlByteMag,0x08);
}

i16 IMU_Accelerometer_get_Y_Value()
{
	return accelerometer_y_value;
}

i16 IMU_Accelerometer_get_Z_Value()
{
	return accelerometer_z_value;
}


