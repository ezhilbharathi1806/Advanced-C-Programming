#include <stdio.h>

// Restricted visibility: Cannot be called by name in other files
static void hidden_function(int value) {
    printf("Static function executed successfully! Value: %d\n", value);
}

// Public visibility: Expose the address via a global function pointer
void (*public_ptr)(int) = hidden_function;