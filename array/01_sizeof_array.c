#include <stdio.h>

int main(void){
	int arr[] = {1, 2, 3};
	printf("size of entire array in bytes = %lu \n", sizeof(arr));
	printf("number of elements present in that array = %lu \n", sizeof(arr)/sizeof(arr[0]));

	return 0;
}
