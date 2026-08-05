#include <stdio.h>

#pragma pack(1)

struct pack{
        char a;
        int b;
        char c;
};

int main (void){
        struct pack p;
        printf("size of structure = %lu \n", sizeof(p));

        return 0;
}

