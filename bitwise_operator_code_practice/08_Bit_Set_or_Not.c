#include <stdio.h>

int main()
{
	int n, pos;
	printf("Enter a number: ");
	scanf("%d",&n);
	printf("Enter position: ");
	scanf("%d",&pos);

	if(n&(1<<pos)){             
	    printf("Bit set 1");
	}else{
	    printf("Bit not set 0");
	}

	return 0;
}
