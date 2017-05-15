#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "IIC.h"


void IIC_Init(void)
{
   SCL=0;
   SDA=0;
   PTBDD_PTBDD0=1;
   PTBDD_PTBDD1=1;
}

void  IIC_start_bit (void)
{
   SCL=1;
   SDA=1;
   //esperar 1.3 US
   asm("nop");
   asm("nop");
   
   SDA=0;
   //esperar 0.6 us
   asm("nop");
   
   SCL=0;
   //esperar 1.3 US
   asm("nop");
   asm("nop");
}

void  IIC_stop_bit   (void)
{
   SCL=1;
   //esperar 0.6 us
   asm("nop");
   
   SDA=1;
   asm("nop");
   asm("nop");
   SCL=0;
   SDA=0;
}

void  IIC_send_byte  (unsigned char dato)
{
   char temp;
   u8 i=8;
   temp=dato;
   do{
      if (temp & 0x80)
      {
         SDA=1;
      }
      else{
         SDA=0;
      }
      SCL=1;//generar pulso de reloj
      asm("nop");
      asm("nop");
      asm("nop");
      SCL=0;
      asm("nop");
      asm("nop");
      asm("nop");
      temp<<=1;   //LSL dato
      
   }while(--i);   //dbnz   i,loop
   SDA=0;//Al salir de cada función poner el dato en 0
}

unsigned char  IIC_ACK_Input(void)
{
   u8 temp;
   PTBDD_PTBDD1=0;   //SDA como entrada
   SCL=1;
   if(SDA==0)
   {
      temp=0;
   }
   else
   {
      temp=1;
   }
   SCL=0;
   PTBDD_PTBDD1=1;//SDA salida
   return temp;
   
}

void IIC_byte_write  (u8 controlByte, u8 direccion, unsigned char dato)
{
	IIC_start_bit();
	IIC_send_byte(controlByte); //Control byte
	if(!IIC_ACK_Input())
	{ 
	   IIC_send_byte(direccion);   
	   if(!IIC_ACK_Input())
	   {
		   IIC_send_byte(dato);
		   if(!IIC_ACK_Input())
		   {
			   IIC_stop_bit();         
		   }
	   } 
	}
	else
	{
		//ERROR
	}
}

unsigned char IIC_read_byte (void)
{
   u8 i;
   unsigned char temp;
   i=8;
   PTBDD_PTBDD1=0;//SDA ENTRADA
   
   do{
	  temp<<=1;
      SCL=1;
      
      if(SDA==1)
      {
         temp++;
      }
      asm("nop");
      asm("nop");
      SCL=0;
      asm("nop");
      asm("nop");
   }while(--i);
   
   PTBDD_PTBDD1=1;
   return temp;
}



void IIC_ACK_output (unsigned char ACK_output)
{
	if(ACK_output==0)
	{
		SDA=0;
	}
	else
	{
		SDA=1;
	}
	SCL=1;
	asm("nop");//los que se necesiten
	asm("nop");
	asm("nop");
	SCL=0;
	SDA=0;
}

unsigned char IIC_random_read(u8 controlByte,unsigned char direccion)
{
	unsigned char temp;
	IIC_start_bit();
	IIC_send_byte(controlByte); //Control byte
	if(!IIC_ACK_Input())
	{
		IIC_send_byte(direccion);   
		if(!IIC_ACK_Input())
		{
			IIC_start_bit();
			IIC_send_byte(controlByte|0x01);
			if(!IIC_ACK_Input())
			{
			   temp=IIC_read_byte();
			   IIC_ACK_output(1);
			   IIC_stop_bit();         
			}
		 }
	
	}
	return temp;
}


