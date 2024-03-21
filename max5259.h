// @File		MAX5259.H		 		
// @Author		JOSIMAR PEREIRA LEITE
// @country		BRAZIL
// @Date		19/03/24
//
//
// Copyright (C) 2024 JOSIMAR PEREIRA LEITE
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
#ifndef MAX5259_H
#define MAX5259_H

#define MAX5259_CS          PORTCbits.RC3
#define MAX5259_SDI         PORTCbits.RC1
#define MAX5259_SD0         PORTCbits.RC2
#define MAX5259_SCK         PORTCbits.RC0

#define MAX5259_CS_TRIS     TRISCbits.RC3
#define MAX5259_SDI_TRIS    TRISCbits.RC1
#define MAX5259_SDO_TRIS    TRISCbits.RC2
#define MAX5259_SCK_TRIS    TRISCbits.RC0

#define MAX5259_DAC_A 0x06
#define MAX5259_DAC_B 0x0E
#define MAX5259_DAC_C 0x16
#define MAX5259_DAC_D 0x1E
#define MAX5259_DAC_E 0x26
#define MAX5259_DAC_F 0x2E
#define MAX5259_DAC_G 0x36
#define MAX5259_DAC_H 0x3E

void MAX5259_write(unsigned char dac, unsigned int data)
{   
    data |= (unsigned int)(dac << 8);
    
    MAX5259_CS = 0;
    
    for(unsigned int mask = 0x8000; mask; mask >>= 1)
    {
        if(data & mask) MAX5259_SDI = 1; else MAX5259_SDI = 0;
            
         __asm__ __volatile__("nop");
         MAX5259_SCK = 1;
         __asm__ __volatile__("nop");
         MAX5259_SCK = 0;
         __asm__ __volatile__("nop");    
    }
    
    MAX5259_CS = 1;
}

void MAX5259_Init(void)
{
    MAX5259_SCK_TRIS = 0;
    MAX5259_SDI_TRIS = 0;
    MAX5259_SDO_TRIS = 1;
    MAX5259_CS_TRIS = 0;
    
    MAX5259_CS = 1;
}

#endif
