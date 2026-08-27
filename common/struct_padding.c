
/* total size of final structure must be the multiple of the largest member's alignment 

structure padding is the extra bytes added to a structure to ensure that each member is aligned properly in memory. 
The size of a structure is determined by the size of its members and any padding that may be added to ensure proper alignment.

structure alignment = alignment of the largest member in the structure.

Structure size is determined by member size(largest member), alignment rules(order of members) and padding inserted by the compiler
*/
#include <stdio.h>

struct pad{
	char a;	// 1 byte						// 1 + 3 bytes padding = 4 bytes
	int b;	// 4 bytes (largest member)		// 4 bytes
	char c;	// 1 byte						// 1 + 3 bytes padding = 4 bytes
};

struct badLayout{
	char a;			// 1 byte						// 1 + 7 bytes padding = 8 bytes
	double b;		// 8 bytes (largest member)		// 8 bytes
	int c;			// 4 bytes						// in next line
	char d;			// 1 byte						// 4 + 1 + 3 bytes padding = 8 bytes
};

struct goodLayout{ //members are arranged in decreasing order of size to minimize padding
	double b;		// 8 bytes (largest member)		// 8 bytes
	int c;			// 4 bytes						// 4 bytes	
	char a;			// 1 byte						// 
	char d;			// 1 byte						// 4 + 1 + 1 + 2 bytes padding = 8 bytes
};
int main (void){
	struct pad p;
	printf("size of structure = %lu \n", sizeof(p)); 	// 12 bytes

	struct badLayout b;
	printf("size of structure = %lu \n", sizeof(b));	// 24 bytes
	
	struct goodLayout g;
	printf("size of structure = %lu \n", sizeof(g));	// 16 bytes

	return 0;
}
