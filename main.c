/*
* Filename: main.c
* Author: Kobe Michiels <kobe.michiels@outlook.com>
* Date: 23-06-2024
* Dependencies: 
    - STM8s Standard Peripheral Library
    - stm8_mp3.h
*/

#include "stm8s.h"
#include "stm8_mp3.h"

void main(void)
{
	mp3_init(); // Initializes the the UART peripheral and resets the MP3 chip
	mp3_select_storage_device(0x02); // Select SD card as storage device
        mp3_set_volume(0x00, 0x0A);     // Set the volume to level 10 (0x0A)
	mp3_play_with_index(0x00, 0x01); // Play song with index 0001
}

#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */
void assert_failed(u8* file, u32 line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif
