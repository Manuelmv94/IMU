#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "IMU.h"





void main(void) {
  EnableInterrupts;
  /* include your code here */
  IMU_Init();
  

  for(;;) {
    __RESET_WATCHDOG();	/* feeds the dog */
    IMU_Accelerometer_UpdateValues();
    IMU_Gyroscope_UpdateValues();
    IMU_Temperature_UpdateValues();
    IMU_Magnetometer_UpdateValues();
    
  } /* loop forever */
  /* please make sure that you never leave main */
}
