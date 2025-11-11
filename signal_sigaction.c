/**
 * @file signal_sigaction.c
 * @brief Program using sigaction to receive SIGUSR1 and print sender PID.
 */

/**
 * Modified by: Bryce Vosburg
 *
 * Brief summary of program:
 * - Registers a SIGUSR1 handler using sigaction (with SA_SIGINFO).
 * - The handler prints the PID of the process that sent SIGUSR1.
 * - Program then waits in an infinite loop, doing nothing until a signal is received.
 *
 * How to send SIGUSR1 to this program:
 * 1. Run this program.
 * 2. From another terminal, send the signal: kill -SIGUSR1 <pid>
 */

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

/**
 * @brief Handler for SIGUSR1 using sigaction with SA_SIGINFO.
 *        Prints the PID of the sending process.
 */
void sigusr1_handler(int sig, siginfo_t *info, void *context) {
    printf("Received SIGUSR1 from PID: %d\n", info->si_pid);
}

int main(void) {

    // Create and configure sigaction struct
    struct sigaction sa;
    sa.sa_sigaction = sigusr1_handler;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);

    // Register handler for SIGUSR1
    sigaction(SIGUSR1, &sa, NULL);

    printf("signal_sigaction running. PID: %d\n", getpid());
    printf("Waiting for SIGUSR1...\n");

    // Infinite wait loop
    while (1) {
        pause();
    }

    return 0;
}
