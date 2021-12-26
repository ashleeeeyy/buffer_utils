//
// Created by Ashley Statuto on 12/25/21.
//

#include <arm/types.h>

int buffer_write_u_int_16(u_int16_t num, char buffer[], int *writehead, int *buffersize);
int buffer_write_u_int_8(u_int8_t num, char buffer[], int *writehead, int *buffersize);

//write non terminated byte array of srclen to the buffer
int buffer_write_char_array(char src[], int srclen, char buffer[], int *writehead, int *buffersize);

//hexdump the duffer to stdin
int debug_output_buffer(char buffer[], int size);

//Write null terminated string to buffer
int buffer_write_string(const char src[], char buffer[], int *writehead, int *buffersize);