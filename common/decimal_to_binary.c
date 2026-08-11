#include <stdio.h>
#include <stdint.h>

void decimal_to_binary(uint32_t n){

	int reg = n , bin_len = 0;
	while(reg > 0){
		reg >>= 1;
		bin_len++;
	}

	uint8_t binary[bin_len];
	uint8_t i = 0;
	while(n > 0){
		binary[i] = n%2;
		n = n/2;
		i++;
	}

	for( int a = i-1; a >= 0; a--){
		printf("%d", binary[a]);
	}
}

int main (void){
	uint32_t num;
	printf("enter a decimal number: ");
	scanf("%d", &num);
	printf("0x%x\n", num);

	decimal_to_binary(num);

	return 0;
}
