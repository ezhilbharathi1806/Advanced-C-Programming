#include <stdio.h>
#include <string.h>

void reverseString(char s[]) {
    int start = 0;
    int end = strlen(s) - 1;
    int temp;

    while (start < end) {
        // Swap
        //temp = s[start];
        //s[start] = s[end];
        //s[end] = temp;
	
	s[start] = s[start] + s[end];
        s[end] = s[start] - s[end];
        s[start] = s[start] - s[end];

        // Move indices closer to the center
        start++;
        end--;
    }
}

int main() {
	char str[] = "hello worldzZ!@#";
	printf("%s\n",str);
	reverseString(str);

	printf("%s\n",str);

    	return 0;
}

