/* Write a C program to extract the first byte and last byte of an unsigned integer using command line argument.*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <unsigned_integer>\n", argv[0]);
        return 1;
    }

    unsigned int number = strtoul(argv[1], NULL, 10);

    unsigned char first_byte = (number & 0xFF);
    unsigned char last_byte = ((number >> 24) & 0xFF);

    printf("Number: %u\n", number);
    printf("First Byte: 0x%02X\n", first_byte);
    printf("Last Byte: 0x%02X\n", last_byte);

    return 0;
}