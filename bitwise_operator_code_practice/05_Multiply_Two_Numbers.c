#include <stdio.h>

int multiply(int a, int b) {
	int result = 0;

	while (b != 0) {                  // Loop until b becomes zero

		if (b & 1) {                 // Check if the least significant bit of b is 1
			result = result + a;     // Add a to result
		}

		a = a << 1; // Left shift a by 1 (equivalent to multiplying by 2)
		b = b >> 1; // Right shift b by 1 (equivalent to dividing by 2)
	}

	return result;
}

int main()
{
	int num1, num2;
	printf("Enter two numbers\n");
	scanf("%d%d",&num1,&num2);

	int product = multiply(num1,num2);
	printf("product = %d", product);

	return 0;
}
