/* Checking the Pointer Size (Most Reliable)
    On a 32-bit system, memory addresses (pointers) are 4 bytes (32 bits) long. 
    On a 64-bit system, pointers are 8 bytes (64 bits) long.
You can check the size of a generic void pointer (void*) using the sizeof operator
*/
#include <stdio.h>

int main() {
    int bits = sizeof(void*) * 8;
    printf("Target Architecture: %d-bit\n", bits);
    return 0;
}

