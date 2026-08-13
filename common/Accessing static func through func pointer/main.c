/*
Calling a "static function" from another file using a function pointer "works perfectly and executes without issue".

While the static keyword restricts the function name's visibility to its own
source file (internal linkage), it only limits access by name at compile-time—it
does not change how the function behaves in memory. Once the executable is built,
a function pointer holds the raw machine address of the compiled code, allowing 
any file with access to that pointer to jump to and execute it.

Common Real-World Use Cases

Using function pointers to run static functions is an industry-standard pattern in C programming for two main reasons:

"Encapsulation (Object-Oriented C):" This pattern is widely used in hardware drivers. 
A driver might define private, hardware-specific functions as static so they don't clutter
the global namespace. It then exposes them to the operating system using a public struct filled with function pointers (e.g., .open, .read, .write).

"Callback Registration:" You can pass a static helper function as a callback argument to an event loop,
logging library, or sorting function (like qsort) located in an entirely different library.
*/

#include <stdio.h>

// Declare the external function pointer from provider.c
extern void (*public_ptr)(int);

int main() {
    // This would cause a compilation error:
    // hidden_function(42); 

    // This works perfectly:
    if (public_ptr != NULL) {
        public_ptr(42); 
    }
    return 0;
}
