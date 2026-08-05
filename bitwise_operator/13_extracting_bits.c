#include <stdio.h>
#include <stdint.h>

int main (void){
	uint32_t a = 0b11011010;
	uint8_t pos = 3;	//position to start extracting
	uint8_t len = 4;	//number bits to extract

	uint32_t mask = (1<<len)-1;
	
	uint32_t result = (a>>pos) & mask;
	printf("0x%x \n", result);

	return 0;
}
