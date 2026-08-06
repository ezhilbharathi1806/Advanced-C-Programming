#include <stdio.h>
#include <string.h>

int main(void){
	char a[] = "hello world";

	int freq[256] = {0};	//to store the frequency of the character
	int printed[256] = {0};	//to track which character have been printed

	int n = strlen(a);	//get length of string

	for( int i = 0; i<n; i++){
		freq[(unsigned char) a[i]]++;	//count frequency of character
	}

	for (int i=0; i<n; i++){		//print frequency once
		if(!printed[(unsigned char) a[i]]){
			printf("%c -> %d \n", a[i], freq[(unsigned char) a[i]]);
			printed[(unsigned char) a[i]] = 1;
		}
	}

	return 0;
}
