// @File		MAIN.C		 		
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
#include "utils.h"
#include "max5259.h"

void main(void)
{
    __delay_ms(500);   
    
    Pic18f2520_init();
    
    MAX5259_Init();
    
    MAX5259_write(MAX5259_DAC_A, 255);
      
    while(1);
    
    return;
}
