#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void wgrep_file(FILE* f, 
    const char* search_str, 
    char** buf, 
    size_t* buf_size);

void wgrep_filename(const char* filename, 
    const char* search_str, 
    char** buf, 
    size_t* buf_size)
{
    FILE* f = fopen(filename, "r");

    if (f == NULL)
    {
        printf("wgrep: cannot open file\n");
        exit(1);
    }

    wgrep_file(f, search_str, buf, buf_size);
}

void wgrep_file(FILE* f, 
    const char* search_str, 
    char** buf, 
    size_t* buf_size)
{
    while (getline(buf, buf_size, f) != -1)
    {
        if (strstr(*buf, search_str) != NULL)
        {
            printf("%s", *buf);
        }
    }
}

int main(int argc, char* argv[])
{
    char* buf = NULL;
    size_t buf_size = 0;

    if (argc < 2)
    {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }

    if (argc == 2)
    {
        wgrep_file(stdin, argv[1], &buf, &buf_size);
        exit(0);
    }

    for (int i = 2; i < argc; ++i)
    {
        wgrep_filename(argv[i], argv[1], &buf, &buf_size);
    }
}