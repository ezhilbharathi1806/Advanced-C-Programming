#include <stdio.h>

#pragma pack(1)

struct pack{
        char a; // 1 byte
        int b;  // 4 bytes
        char c; // 1 byte
};

int main (void){
        struct pack p;
        printf("size of structure = %lu \n", sizeof(p));        // 6 bytes

        return 0;
}

/*
1. Performance Degradation (Alignment Issues)
        When a structure is packed, the compiler may generate additional instructions to access misaligned members, leading to performance degradation. 
        Accessing misaligned data can result in slower memory access times and increased CPU cycles.

2. Hardware Exceptions and Crashes
        Some architectures(like older ARM, MIPS, or SPARC) do not support unaligned memory access, 
        and attempting to access misaligned members can lead to hardware exceptions or crashes. 
        This can result in program instability and unexpected behavior.

3. Portability Issues
        Packed structures may not be portable across different architectures or compilers.
        Packing relies on compiler-specific extensions (#pragma pack for MSVC/GCC, __attribute__((packed)) for GCC/Clang), making code less portable across different compilers.

4. Bloated Instructions: 
        While packing reduces the RAM size of the struct, the compiler must generate extra instructions to handle the unaligned data, which can increase the binary executable size.
*/