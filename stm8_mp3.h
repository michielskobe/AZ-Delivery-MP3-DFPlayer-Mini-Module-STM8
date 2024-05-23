/**
* Filename: stm8_mp3.h
* Author: Kobe Michiels <kobe.michiels@outlook.com>
* Date: 23-06-2024
* Dependencies: 
    - STM8s Standard Peripheral Library.
*/

#ifndef _STM8_MP3_H_
#define _STM8_MP3_H_

#include "stm8s.h"

#define START_BYTE 0x7E
#define VERSION_BYTE 0xFF
#define COMMAND_LENGTH 0x06
#define ACKNOWLEDGE 0x01
#define END_BYTE 0xEF

/**
* This function is responsible for executing a command.
* It expects a command and two parameters.*/
void mp3_execute_command(uint8_t command, uint8_t data1, uint8_t data2);

/**
* This function is responsible for initializing the mp3 module.
* It enables the UART, resets the module and sets some basic configurations.
* For the storage device is selects SD card and for the volume is selects level 10.
*/
void mp3_init(void);

/**
* This function is responsible for playing the next song.
*/
void mp3_play_next(void);

/**
* This function is responsible for playing the previous song.
*/
void mp3_play_previous(void);

/**
* This function is responsible for playing a specific song.
* It expects a parameters to indicate the index of the song.
*/
void mp3_play_with_index(uint8_t song_high, uint8_t song_low);

/**
* This function is responsible for increasing the volume one level.
*/
void mp3_volume_up(void);

/**
* This function is responsible for decreasing the volume one level.
*/
void mp3_volume_down(void);

/**
* This function is responsible for setting the volume.
* It expects a parameter between 0 and 30 to indicate the volume.
*/
void mp3_set_volume(uint8_t volume_high, uint8_t volume_low);

/**
* This function is responsible for setting EQ.
* It expects a parameter to indicate the EQ.
* 0x00 / 0x01 / 0x02 / 0x03 / 0x04 / 0x05
* Normal/Pop/Rock/Jazz/Classic/Base
*/
void mp3_set_eq(uint8_t eq);

/**
* This function is responsible for looping a specific song.
* It expects a parameters to indicate the index of the song.
*/
void mp3_loop_specific_song(uint8_t song_high, uint8_t song_low);

/**
* This function is responsible for selecting the storage device.
* It expects a parameter to select the device.
* Select storage device to USB memeory: device = 0x01
* Select storage device to SD card: device = 0x02
*/
void mp3_select_storage_device(uint8_t device);

/**
* This function is responsible for entering the chip in sleep mode.
*/
void mp3_sleep(void);

/**
* This function is responsible for waking the chip up from sleep mode.
*/
void mp3_wake_up(void);

/**
* This function is responsible for resetting the chip.
*/
void mp3_reset_chip(void);

/**
* This function is responsible for resuming the playback.
*/
void mp3_play(void);

/**
* This function is responsible for pausing the playback.
*/
void mp3_pause(void);

/**
* This function is responsible for playing a song in a folder.
* It expects a 2 parameters to indicate the folder and the song.
*/
void mp3_play_in_folder(uint8_t folder, uint8_t song);

/**
* This function is responsible for setting audio amplification.
* It expects a 2 parameters to indicate the status and the level.
* Enable audio amplification: 0x01
* Disable audio amplification: 0x00
*/
void mp3_audio_amplification(uint8_t status, uint8_t level);

/**
* This function is responsible for looping all songs.
* It expects a parameter to indicate the status of the loop.
* Start loop: 0x01
* Stop loop: 0x00
* Stopping the loop also stops the playback.
*/
void mp3_loop_all(uint8_t status);

/**
* This function is responsible for playing a song from the mp3 folder.
* It expects a parameters to indicate the index of the song.
*/
void mp3_play_in_mp3_folder(uint8_t song_high, uint8_t song_low);

/**
* This function is responsible for playing a song from the ADVERT folder.
* It expects a parameters to indicate the index of the song.
*/
void mp3_play_in_advert_folder(uint8_t song_high, uint8_t song_low);

/**
* This function is responsible for playing a specific song from a folder.
* It expects a parameter to indicate the folder and the song.
* The 4 MSB's of the parameter indicate the folder. The 12 other bits indicate the song.
*/
void mp3_play_song_in_folder(uint16_t destination);

/**
* This function is responsible for stopping an add and resuming the previous playback.
*/
void mp3_stop_add(void);

/**
* This function is responsible for stopping the playback.
*/
void mp3_stop(void);

/**
* This function is responsible for looping a song in a folder.
* It expects a 2 parameters to indicate the folder and the song.
*/
void mp3_loop_song_in_folder(uint8_t folder, uint8_t song);

/**
* This function is responsible for enabling random playback of the songs on the device.
*/
void mp3_random(void);

/**
* This function is responsible for setting a single loop play.
* It expects a parameter to indicate the status of the loop.
* Start single loop: 0x00
* Stop single loop: 0x01
*/
void mp3_set_single_loop(uint8_t status);

/**
* This function is responsible for setting DAC.
* It expects a parameter to indicate the status of DAC.
* Start DAC output: 0x00
* Stop DAC output: 0x01
*/
void mp3_set_dac(uint8_t status);

#endif /* _STM8_MP3_H_*/
