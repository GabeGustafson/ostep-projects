#include <stdio.h>
#include <stdlib.h>

#define SIZE 512

void wcat_file(char* file, char buf[])
{
    FILE* f = fopen(file, "r");

    if (f == NULL)
    {
        printf("wcat: cannot open file\n");
        exit(1);
    }

    while (fgets(buf, SIZE, f) != NULL)
    {
        printf("%s", buf);
    }
}

int main(int argc, char* argv[])
{
    char buf[SIZE];

    for (int i = 1; i < argc; ++i)
    {
        wcat_file(argv[i], buf);
    }
        
    return 0;
}