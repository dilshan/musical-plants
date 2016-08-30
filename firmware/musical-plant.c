//****************************************************************************
// Musical Plants - PIC18F4550 Firmware (Version 1.0)
// Designed for CoCA Emerge + Tech project.
//
// Copyright (c) 2016 Dilshan R Jayakody [jayakody2000lk at gmail dot com].
//
// Permission is hereby granted, free of charge, to any person obtaining a 
// copy of this software and associated documentation files (the "Software"), 
// to deal in the Software without restriction, including without limitation 
// the rights to use, copy, modify, merge, publish, distribute, sublicense, 
// and/or sell copies of the Software, and to permit persons to whom the 
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included 
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS 
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL 
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
// DEALINGS IN THE SOFTWARE.
//****************************************************************************

#define DATA_PACKET_HEADER 0xC1

unsigned char readbuff[64] absolute 0x500;
unsigned char writebuff[64] absolute 0x540;

void interrupt()
{
   USB_Interrupt_Proc();
}

void main() 
{
  unsigned char arrayPos;
  unsigned char lastPortA = 0xFF, lastPortB = 0xFF, lastPortD = 0xFF;
  
  // Setup MCU register configuration.
  ADCON1 |= 0x0F;
  CMCON  |= 7;
  TRISA = 0xFF;
  TRISB = 0xFF;
  TRISD = 0xFF;
  PORTA = 0x00;
  PORTB = 0x00;
  PORTD = 0x00;
  
  // Enable USB HID.
  HID_Enable(&readbuff, &writebuff);
  
  // Setup HID data buffer.
  for(arrayPos = 0; arrayPos < 64; arrayPos++)
  {
    writebuff[arrayPos] = 0x00;
  }
  
  Delay_ms(100);

  // Service loop.
  while(1)
  {
    // Looking for any changes in input ports.
	if((PORTA != lastPortA) || (PORTB != lastPortB) || (PORTD != lastPortD))
    {
      lastPortA = PORTA;
      lastPortB = PORTB;
      lastPortD = PORTD;
      
      writebuff[0] = DATA_PACKET_HEADER;
      writebuff[1] = PORTA;
      writebuff[2] = PORTB;
      writebuff[3] = PORTD;
      
	  // Submit port status to host over allocated HID channel.
      while(!HID_Write(&writebuff, 64));
    }
    
    Delay_ms(100);
  }
}