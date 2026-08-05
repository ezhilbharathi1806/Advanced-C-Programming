#include <stdio.h>

int main()
{
    int a, b;
    printf("Enter two number: ");
    scanf("%d%d",&a,&b);
    
    while(b!=0){
        int data = a&b;
        a = a^b;
        b = data<<1;
    }
    
    printf("Sum = %d",a);

    return 0;
}
