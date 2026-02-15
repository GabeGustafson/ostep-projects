#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>

#define MEGABYTES_TO_BYTES (1024 * 1024)

void memory_user(char* megabytes)
{
    errno = 0;
    const size_t numMegabytes = strtol(megabytes, NULL, 10);
    if (errno == ERANGE)
    {
        printf("Range error: %zu\n", numMegabytes);
        exit(1);
    }

    const size_t numBytes = numMegabytes * MEGABYTES_TO_BYTES;

    char data[numBytes];

    printf("memory-user pid: %d\n", getpid());
    fflush(stdout);

    size_t i = 0;
    while (1)
    {
        data[i] = 1;
        i = (i + 1) % numBytes;
    }
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("usage: main <megabytes>\n");
        exit(1);
    }

    memory_user(argv[1]);

    return 0;
}