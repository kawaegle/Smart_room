#include "../include/client.h"
#include <stdio.h>

int set_mode(int mode)
{
    if (mode == 1)
        white();
    if (mode == 2)
        random_data();
    if (mode == 3)
        random_seed();

    return (0);
}

int white(void)
{
    printf("white\n");
    return (0);
}

int random_data(void)
{
    printf("data\n");
    return (0);
}

int random_seed(void)
{
    printf("seed\n");
    return (0);
}
