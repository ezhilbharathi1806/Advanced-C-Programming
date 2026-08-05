#include <stdio.h>
#include <stdint.h>

uint8_t count_set_bits(uint32_t num) {
    uint8_t count = 0;
    while (num > 0) {
        num &= (num - 1); // Clears the lowest set bit
        count++;
    }
    return count;
}

int main() {
    uint32_t num = 0b10101010; // Example number
    printf("Number of set bits in %u: %u\n", num, count_set_bits(num));
    return 0;
}