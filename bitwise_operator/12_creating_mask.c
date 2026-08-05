#include <stdio.h>
#include <stdint.h>

int main (void){
	uint8_t mask_len = 8;
	uint32_t mask_val = (1 << mask_len) - 1;
	printf(" mask value of length %d = 0x%x \n",mask_len,mask_val);

	return 0;
}
