/* Write a program to extract each byte of a given number and store them in a variable and display.*/
#include <stdio.h>

int main() {
    unsigned int number;
    printf("Enter an unsigned integer: ");
    scanf("%u", &number);

    unsigned char byte1 = (number & 0xFF);
    unsigned char byte2 = ((number >> 8) & 0xFF);
    unsigned char byte3 = ((number >> 16) & 0xFF);
    unsigned char byte4 = ((number >> 24) & 0xFF);

    printf("Number: %u\n", number);
    printf("Byte 1: 0x%02X\n", byte1);
    printf("Byte 2: 0x%02X\n", byte2);
    printf("Byte 3: 0x%02X\n", byte3);
    printf("Byte 4: 0x%02X\n", byte4);

    return 0;
}