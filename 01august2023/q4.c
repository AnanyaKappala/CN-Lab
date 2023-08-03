/*Write a program to modify the above program to regenerate or to display original numbers from the structure 
members. And also display the total number.*/
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

    unsigned int regenerated_number =
        (unsigned char)packet_data.a1 |
        ((unsigned char)packet_data.a2[0] << 8) |
        ((unsigned char)packet_data.a2[1] << 16) |
        ((unsigned char)packet_data.a3 << 24);

    printf("Regenerated Number: %u\n", regenerated_number);

    unsigned int total_number = 0;
    for (int i = 0; i < sizeof(packet_data); i++) {
        total_number = (total_number << 8) | ((unsigned char*)&packet_data)[i];
    }

    printf("Total Number: %u\n", total_number);

    return 0;
}
