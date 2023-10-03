/**
 * the delay time relates to the average pulse length for Pi 4:
 * pulse length = delay + 68
 *
 * thi means, if you want to set a delay less then 70us or 90us, don't use
 * nanosleep.
 *
 * void bcm2835_delayMicroseconds(time)
 * uses a busy wait loop for times shorter than 450µs and a system delay
 * like usleep or nanosleep for longer periods.
 */
#define _DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <bcm2835.h>
#include <time.h>
#include <signal.h>

#define ever \
    ;        \
    ;

void sigint_handler(int signal);

int main(int argc, char **argv)
{
    // Set up the signal handler for Ctrl+C
    if (signal(SIGINT, sigint_handler) == SIG_ERR)
    {
        perror("Error setting up signal handler");
        return 1;
    }

    if (!bcm2835_init())
    {
        return (EXIT_FAILURE);
    }

    bcm2835_gpio_fsel(RPI_BPLUS_GPIO_J8_07, BCM2835_GPIO_FSEL_OUTP);

    int n = 10;

    for (ever)
    {
        for (volatile int i = 0; i < n; i++)
            ;
        bcm2835_gpio_write(RPI_BPLUS_GPIO_J8_07, HIGH);
        for (volatile int i = 0; i < n; i++)
            ;
        bcm2835_gpio_write(RPI_BPLUS_GPIO_J8_07, LOW);
    }

    bcm2835_close();

    return (EXIT_SUCCESS);
}

// Function to handle Ctrl+C (SIGINT) signal
void sigint_handler(int signal)
{
    printf("\nCtrl+C received. Cleaning up and exiting...\n");
    // Perform cleanup tasks here
    // Close files, release memory, etc.
    bcm2835_close();

    exit(EXIT_SUCCESS); // Exit the program gracefully
}