#include <stdio.h>

int main (void){
	char s[30];
	printf("enter string with whitespaces");
	scanf("%[^\n]s",s);
	printf("%s\n",s);

	return 0;
}
