#include <stdio.h>

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);  //get two numbers from the user
    
    printf("Before swapping \na=%d\tb=%d\n",a,b);
    a = a^b;
    b = a^b;
    a = a^b;
    printf("After swapping \na=%d\tb=%d",a,b);

    return 0;
}
