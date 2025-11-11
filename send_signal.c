/**
 * @file send_signal.c
 * @brief Sends SIGUSR1 to a target PID using sigqueue, including a random int value.
 *
 * Modified by: Bryce Vosburg
 *
 * Brief summary of program:
 * - Takes the receiver PID as a command line argument.
 * - Generates a random integer (seeded with time()).
 * - Sends SIGUSR1 using sigqueue with the random integer stored in sival_int.
 */

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pid>\n", argv[0]);
        return 1;
    }

    // Convert command line argument to integer PID
    pid_t pid = atoi(argv[1]);

    srand(time(NULL));
    int value = rand();

    printf("Sending value %d to PID %d via SIGUSR1...\n", value, pid);

    // Prepare sigqueue value
    union sigval sv;
    sv.sival_int = value;

    // Send SIGUSR1 with accompanying integer
    if (sigqueue(pid, SIGUSR1, sv) == -1) {
        perror("sigqueue failed");
        return 1;
    }

    printf("Signal sent successfully.\n");
    return 0;
}
