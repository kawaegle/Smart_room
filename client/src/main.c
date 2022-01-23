#include "../include/client.h"

int main(int argc, char **argv)
{
    if (argc != 2) {
        helper();
        return (84);
    }
    int status = 0;
    int mode = atoi(argv[1]);
    if ( mode > 3) {
        printf("The mode is not supported for the moment\n");
        return (84);
    }
    status = set_mode(mode);
    return (0);
}
