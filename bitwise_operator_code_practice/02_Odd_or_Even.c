#include <stdio.h>

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    
    if((n&1)==0){             // eg n=5 = 0101 & 0001 = 1 else part will get executed So odd
        printf("Even number: %d",n);
    }else{
        printf("Odd number: %d",n);
    }

    return 0;
}
