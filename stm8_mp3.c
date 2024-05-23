/**
* Filename: stm8_mp3.c
* Author: Kobe Michiels <kobe.michiels@outlook.com>
* Date: 23-06-2024
* Dependencies: 
    - STM8s Standard Peripheral Library
    - stm8_mp3.h
*/

#include "stm8_mp3.h"

void mp3_execute_command(uint8_t command, uint8_t data1, uint8_t data2){
		uint32_t count;
		int index;
    // Calculate the checksum
    uint16_t checksum = -(VERSION_BYTE + COMMAND_LENGTH + command + ACKNOWLEDGE + data1 + data2);
    uint8_t checksum_high = checksum >> 8; // Right-Shift to get checksum high byte
    uint8_t checksum_low = checksum & 0xFF; // Logical AND to get checksum low byte

    // Build the command
    uint8_t cmd[10] = {START_BYTE, VERSION_BYTE, COMMAND_LENGTH, command, ACKNOWLEDGE, data1, data2, checksum_high,
                            checksum_low, END_BYTE};

    // Send command to MP3 module over UART
    for (index = 0; index < 10; index++) {
        UART2_SendData8(cmd[index]);
				while (UART2_GetFlagStatus(UART2_FLAG_TXE) == RESET){
					nop();
				}
    }
		while (UART2_GetFlagStatus(UART2_FLAG_RXNE) == RESET){
			nop();
		}
		// Delay for command processing
		for (count = 0; count < 100000; count++) {
			nop();
		}
}

void mp3_init(void){
		UART2_DeInit();
		/** Baud Rate 9600, 8 bits Data, One stop bit is  transmitted at the end of frame, No Parity, Sync mode Disable, SLK pin Disable, Transmit Enable and Receive Enable */
		UART2_Init(9600, UART2_WORDLENGTH_8D, UART2_STOPBITS_1, UART2_PARITY_NO, UART2_SYNCMODE_CLOCK_DISABLE, UART2_MODE_TXRX_ENABLE);
		UART2_Cmd(ENABLE);
    mp3_reset_chip();
    mp3_select_storage_device(0x02); // Select SD card as storage device
    mp3_set_volume(0x00, 0x0A);     // Set the volume to level 10 (0x0A)
}

void mp3_play_next(){
    mp3_execute_command(0x01, 0x00, 0x00);
}

void mp3_play_previous(){
    mp3_execute_command(0x02, 0x00, 0x00);
}

void mp3_play_with_index(uint8_t song_high, uint8_t song_low){
    mp3_execute_command(0x03, song_high, song_low);
}

void mp3_volume_up(){
	mp3_execute_command(0x04, 0x00, 0x00);
}

void mp3_volume_down(){
	mp3_execute_command(0x05, 0x00, 0x00);
}

void mp3_set_volume(uint8_t volume_high, uint8_t volume_low){
	mp3_execute_command(0x06, volume_high, volume_low);
}

void mp3_set_eq(uint8_t eq){
	mp3_execute_command(0x07, 0x00, eq);
}

void mp3_loop_specific_song(uint8_t song_high, uint8_t song_low) {
	mp3_execute_command(0x08, song_high, song_low);
}

void mp3_select_storage_device(uint8_t device){
	mp3_execute_command(0x09, 0x00, device);
}

void mp3_sleep() {
	mp3_execute_command(0x0A, 0x00, 0x00);
}

void mp3_wake_up() {
	mp3_execute_command(0x0B, 0x00, 0x00);
}

void mp3_reset_chip(){
	mp3_execute_command(0x0C, 0x00, 0x00);
}

void mp3_play(){
    mp3_execute_command(0x0D, 0x00, 0x00);
}

void mp3_pause(){
    mp3_execute_command(0x0E, 0x00, 0x00);
}

void mp3_play_in_folder(uint8_t folder, uint8_t song){
    mp3_execute_command(0x0F, folder, song);
}

void mp3_audio_amplification(uint8_t status, uint8_t level){
    mp3_execute_command(0x10, status, level);
}

void mp3_loop_all(uint8_t status){
    mp3_execute_command(0x11, 0x00, status);
}

void mp3_play_in_mp3_folder(uint8_t song_high, uint8_t song_low) {
	mp3_execute_command(0x12, song_high, song_low);
}

void mp3_play_in_advert_folder(uint8_t song_high, uint8_t song_low) {
	mp3_execute_command(0x13, song_high, song_low);
}

void mp3_play_song_in_folder(uint16_t destination){
		uint8_t destination_high = destination >> 8; 
    uint8_t destination_low = destination & 0xFF;
    mp3_execute_command(0x14, destination_high, destination_low);
}

void mp3_stop_add(){
    mp3_execute_command(0x15, 0x00, 0x00);
}

void mp3_stop(){
    mp3_execute_command(0x16, 0x00, 0x00);
}

void mp3_loop_song_in_folder(uint8_t folder, uint8_t song){
    mp3_execute_command(0x17, folder, song);
}

void mp3_random(){
    mp3_execute_command(0x18, 0x00, 0x00);
}

void mp3_set_single_loop(uint8_t status) {
		mp3_execute_command(0x19, 0x00, status);
}

void mp3_set_dac(uint8_t status) {
		mp3_execute_command(0x1A, 0x00, status);
}
