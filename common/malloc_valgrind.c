#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *str = (char *) malloc(20 * sizeof(char));
    strcpy(str,"hello from malloc");
    printf("%s\n", str);

    free(str);

    int *a = (int *) calloc(1, sizeof(int));
    *a = 10;
    printf("%d\n", *a);
    free(a);

    return 0;
}


/*
> gcc -g -O0 program.c -o output
> valgrind ./output
> valgrind --leak-check=full --show-leak-kinds=all ./output
*/