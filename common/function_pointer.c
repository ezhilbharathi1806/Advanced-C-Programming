#include <stdio.h>

void sample(void){
	printf("sample function is called \n");
}

int main (void){
	void (*func_ptr)(void) = sample;
	func_ptr();

	return 0;
}
