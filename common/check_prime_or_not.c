#include <stdio.h>

int prime_or_not(int num){
	for (int i = 2 ; i <= num/2 ; i++){
	       if( num % i == 0){
		       return 0;
		       break;
	       }
	}
	return 1;
}

int main(void){
	int n;
	printf("enter a number:");
	scanf("%d", &n);

	prime_or_not(n) ? printf("prime") : printf("not prime");

	return 0;

}
