#include <stdio.h>

#pragma pack(1)

struct pack{
        char a:1;       // 1 bit for char a
        int b:4;        // 4 bits for int b
        char c:1;       // 1 bit for char c
};

int main (void){
        struct pack p;
        printf("size of structure = %lu \n", sizeof(p));        // 1 byte

        return 0;
}

// without packing the size of struct would be 4 bytes
/*Resulting Size: If all 6 bits fit inside a single 4-byte (int) storage slot, the struct size will be 4 bytes. 
If the compiler enforces strict type isolation (treating char and int as entirely distinct tracking slots), it pads out the layout resulting in 8 bytes
*/ 