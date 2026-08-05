#include <stdio.h>

struct pad{
	char a;
	int b;
	char c;
};

int main (void){
	struct pad p;
	printf("size of structure = %lu \n", sizeof(p));
	
	return 0;
}
