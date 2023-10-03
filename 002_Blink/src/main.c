#include <stdio.h>
#include <stdlib.h>
#include <bcm2835.h>

#define ever \
    ;        \
    ;

int main(int argc, char **argv)
{
    if (!bcm2835_init())
    {
        return 1;
    }

    bcm2835_gpio_fsel(RPI_BPLUS_GPIO_J8_07, BCM2835_GPIO_FSEL_OUTP);

    for (ever)
    {
        bcm2835_gpio_write(RPI_BPLUS_GPIO_J8_07, HIGH);
        bcm2835_gpio_write(RPI_BPLUS_GPIO_J8_07, LOW);
    }

    bcm2835_close();

    return (EXIT_SUCCESS);
}