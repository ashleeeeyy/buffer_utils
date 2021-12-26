//
// Created by Ashley Statuto on 12/25/21.
//

#include <printf.h>
#include <arpa/inet.h>
#include "bytebuf.h"

int buffer_write_u_int_16(u_int16_t num, char buffer[], int *writehead){
    //set a int16 pointer starting at the writehead in the arrays memory
    u_int16_t *il = (u_int16_t *) (&buffer[*writehead]);

    //set the value at that address to num
    //remember: doing il = num would be changing the pointer, not the pointers value!
    *il = num;

    //increment the writehead by the size
    *writehead = (int) (*writehead + sizeof num);

    return 0;
}

int buffer_write_u_int_8(u_int8_t num, char buffer[], int *writehead){
    u_int8_t *il = (u_int8_t *) (&buffer[*writehead]);
    *il = num;
    *writehead = (int) (*writehead + sizeof num);

    return 0;
}

int buffer_write_char_array(char src[], int srclen, char buffer[], int *writehead){
    int i;
    //write each byte of the source to the destination
    for (i = 0; i < srclen; ++i) {
        buffer_write_u_int_8(src[i], buffer, writehead);
    }

    return 0;
}

int buffer_write_string(const char src[], char buffer[], int *writehead){
    //copy pointer as to not modify i
    const char* string = src;
    //get the size
    int size = 0;
    while(*string != '\0'){
        size++;
        ++string;
    }
    buffer_write_u_int_8(size, buffer, writehead);
    //reset pointer
    string = src;
    //write the actual data

    while(*string != '\0'){
        buffer_write_u_int_8(*string, buffer, writehead);
        ++string;
    }

    return 0;
}

int debug_output_buffer(char buffer[], int size){
    for (int i = 0; i < size; ++i, ++buffer){
        printf("%02x ", (unsigned char) *buffer);
        if ((i+1)%16 == 0) printf("\n");
    }

    return 0;
}