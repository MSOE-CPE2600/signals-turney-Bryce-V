/**
 * File: signal_alarm.c
 * Modified by: Bryce Vosburg
 * 
 * Brief summary of program:
 * This program installs a signal handler for SIGALRM, schedules an alarm
 * to occur in 5 seconds, and prints a message when the alarm signal is received.
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

/**
 * @brief Handler for SIGALRM. Prints a message when the alarm occurs.
 */
void alarm_handler(int sig) {
    printf("Received SIGALRM! 5 seconds have passed.\n");
}

int main(void) {
    signal(SIGALRM, alarm_handler);

    alarm(5);

    // Wait for the signal
    while (1) {
        pause();
    }

    return 0;
}
