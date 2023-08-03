/*Write a c program to extract each byte as a character from the representation of multi byte data types and store the extracted bytes in the following structure.
struct pakcet
{
char a1;
char a2[2];
char a3;
}
And display the contents of the structure.*/
#include <stdio.h>

struct packet {
    char a1;
    char a2[2];
    char a3;
};

int main() {
    unsigned int number;
    printf("Enter an unsigned integer: ");
    scanf("%u", &number);

    struct packet packet_data;

    packet_data.a1 = (number & 0xFF);
    packet_data.a2[0] = ((number >> 8) & 0xFF);
    packet_data.a2[1] = ((number >> 16) & 0xFF);
    packet_data.a3 = ((number >> 24) & 0xFF);

    printf("Packet Contents:\n");
    printf("a1: 0x%02X\n", packet_data.a1);
    printf("a2[0]: 0x%02X\n", packet_data.a2[0]);
    printf("a2[1]: 0x%02X\n", packet_data.a2[1]);
    printf("a3: 0x%02X\n", packet_data.a3);

    return 0;
}
