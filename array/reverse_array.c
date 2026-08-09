#include <stdio.h>

void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    int temp;

    while (start < end) {
        // Swap elements
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // Move indices closer to the center
        start++;
        end--;
    }
}

int main() {
	int arr[] = {10, 20, 30, 40, 50};
   	int size = sizeof(arr) / sizeof(arr[0]);

    	reverseArray(arr, size);

    	for (int i = 0; i < size; i++) {
        	printf("%d ", arr[i]);
    	}
    	return 0;
}

