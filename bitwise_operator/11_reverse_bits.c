#include <stdio.h>
#include <stdint.h>

uint32_t reverse_bits(uint32_t num) {
    uint32_t reverse = 0;
    for (int i = 0; i < 32; i++) {
        reverse <<= 1;          // Shift reverse left by 1
        reverse |= (num & 1);   // Add the least significant bit of num to reverse
        num >>= 1;              // Shift num right by 1
    }
    return reverse;
}

int main() {
    uint32_t num = 0b00000000000000000000000000001010; // Example number
    printf("Original number: %u (0x%X)\n", num, num);
    uint32_t reversed = reverse_bits(num);
    printf("Reversed number: %u (0x%X)\n", reversed, reversed);
    return 0;
}