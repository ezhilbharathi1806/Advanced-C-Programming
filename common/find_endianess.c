#include <stdio.h>
#include <stdint.h>

int main(void){
	uint32_t val = 0x12345678;

	char *r = (char *) &val;

	for ( int i =0 ; i < 4; i++){
		printf("Address of 0x%X = %p \n", r[i], &r[i]);
	}

	return 0;
}
