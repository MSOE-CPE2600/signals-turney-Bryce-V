/**
 * @file signal_handler.c
 * @brief Sets a signal handler for SIGINT. The handler prints a message but does NOT exit.
 */

/**
 * Modified by: Bryce Vosburg
 * 
 * Brief summary of modifications:
 * - Removed the call to exit() inside the SIGINT handler so the program no longer quits.
 * - Program now continues running after receiving SIGINT.
 * - Must use SIGKILL or another terminating signal to end the program.
 */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGINT - prints a message but does NOT exit
 */
void handle_signal() {
    printf("\nReceived SIGINT (Ctrl+C), but not exiting.\n");
}

int main() {

    // Register handler for SIGINT
    signal(SIGINT, handle_signal);

    // Infinite loop so program stays alive
    while (1) {
        printf("Sleeping...\n");
        sleep(1);
    }

    return 0;
}
