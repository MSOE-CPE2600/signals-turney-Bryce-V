/**
 * @file recv_signal.c
 * @brief Program that waits for SIGUSR1 and prints the integer sent using sigqueue.
 *
 * Modified by: Bryce Vosburg
 *
 * Brief summary of program:
 * - Registers a SIGUSR1 handler using sigaction with SA_SIGINFO enabled.
 * - Handler prints the integer stored in si_value.sival_int.
 * - Program loops forever waiting for incoming SIGUSR1 signals.
 */

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

/**
 * @brief Handler for SIGUSR1. Prints the integer sent from the sender.
 */
void usr1_handler(int sig, siginfo_t *info, void *context) {
    int value = info->si_value.sival_int;
    printf("Received SIGUSR1 with value: %d\n", value);
}

int main(void) {
    // Configure sigaction structure
    struct sigaction sa;
    sa.sa_sigaction = usr1_handler;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);

    // Install handler for SIGUSR1
    sigaction(SIGUSR1, &sa, NULL);

    printf("recv_signal running. PID: %d\n", getpid());
    printf("Waiting for SIGUSR1...\n");

    // Wait forever
    while (1) {
        pause();
    }

    return 0;
}
