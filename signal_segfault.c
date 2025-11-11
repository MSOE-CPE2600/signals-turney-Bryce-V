/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault.
 */

/**
 * Modified by: Bryce Vosburg
 * 
 * Brief summary of modifications:
 * - Added a signal handler for SIGSEGV.
 * - Handler prints a message when a segmentation fault occurs.
 * - Program continues executing after the handler returns, causing the
 *   same invalid memory access to run again (expected behavior).
 */

#include <stdio.h>
#include <signal.h>

/**
 * @brief SIGSEGV handler: prints a message but does NOT exit.
 */
void segv_handler(int sig) {
    printf("Caught SIGSEGV, a segmentation fault occurred.\n");
}

int main(int argc, char* argv[]) {

    // Register handler for SIGSEGV
    signal(SIGSEGV, segv_handler);

    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer (triggers SIGSEGV)
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}
