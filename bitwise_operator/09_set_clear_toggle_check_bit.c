// Macros to manipulate the n-th bit of a register REG.

#include <stdio.h>

#define SET_BIT(REG, BIT)	((REG) |= (1U << BIT))
#define CLEAR_BIT(REG, BIT)	((REG) &= ~(1U << BIT)) 
#define TOGGLE_BIT(REG, BIT)	((REG) ^= (1U << BIT))
#define CHECK_BIT(REG, BIT)	(REG >> BIT) & 1U


int main(){
	unsigned int reg = 0;

	printf("Initial value = %u (0x%X) \n", reg, reg);

	// set bit position 3
	SET_BIT(reg, 3);
	printf("After setting 3rd bit, value = %u (0x%X) \n", reg, reg);

	// clear bit position 3
	CLEAR_BIT(reg, 3);
	printf("After clearing 3rd bit, value = %u (0x%X) \n", reg, reg);

	// toggle bit position 3
	TOGGLE_BIT(reg, 3);
	printf("After toggling 3rd bit, value = %u (0x%X) \n", reg, reg);

	// check bit position 3
	if (CHECK_BIT(reg, 3)) {
		printf("3rd bit is set\n");
	} else {
		printf("3rd bit is clear\n");
	}

	return 0;
}
