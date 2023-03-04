/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "pico/stdlib.h"
#include "pico/binary_info.h"

#include "hardware/gpio.h"
#include "hardware/adc.h"
#include "hardware/spi.h"
#include "hardware/pll.h"
#include "hardware/clocks.h"
#include "hardware/structs/pll.h"
#include "hardware/structs/clocks.h"


const int BUFFER_LENGTH = 2;
//const int PICO_ERROR_TIMEOUT = 100;

uint16_t get_block(uint8_t *buffer) 
{
  uint16_t buffer_index= 0;
  while (true) 
  {
    int c = getchar_timeout_us(100);
    if (c != PICO_ERROR_TIMEOUT && buffer_index < BUFFER_LENGTH) 
    {
      buffer[buffer_index++] = (c & 0xFF);
    } 
    else 
    {
      break;
    }
  }
  return buffer_index;
}
int main()
{
     // Enable UART so we can print
    stdio_init_all();
    while(true)
    {   
        //sleep_ms(1000); // 1s delay
        //int c = getchar_timeout_us(1000000);
        char c = getchar();
        printf("c : %c",c);
        if (c == 'x')
        {
            printf("got x \n");
        }
        else
        {
            printf("hello from usb!!! \n");
        }
    }
}
