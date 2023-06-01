#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <math.h>

#define llu long long unsigned
#define ld long double

/**
 * main - Factorizes as many numbers as possible into
 * a product of two smaller numbers.
 * numbers are read from a file one per line.
 * @argc: argument counter
 * @argv: argument vector
 *
 * Return: 0 if Succes, EXIT_FAILURE otherwise.
 */
int main(int argc, char *argv[])
{
    FILE *file_ptr;
    char *line_buf;
    size_t buf_size = 1024;
    ld number, i;
    ssize_t n_read;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: factors <file>\n");
        exit(EXIT_FAILURE);
    }

    file_ptr = fopen(argv[1], "r");
    if (!file_ptr)
    {
        fprintf(stderr, "Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    line_buf = malloc(1024 * sizeof(char));
    if (!line_buf)
    {
        fprintf(stderr, "Allocation erroe\n");
        exit(EXIT_FAILURE);
    }

    n_read = getline(&line_buf, &buf_size, file_ptr);
    while (n_read != -1)
    {
        number = strtold(line_buf, NULL);
        if ((llu) number % 2 == 0)
        {
            printf("%.0Lf=%llu*%i\n", number, (llu)(number / 2), 2);
        }
        else
        {
            for (i = 3; i < number; i+=2)
            {
                if ((llu)number % (llu) i == 0)
                {
                    printf("%.0Lf=%llu*%.0Lf\n", number, (llu)(number / i), i);
                    break;
                }
            }
        }
        n_read = getline(&line_buf, &buf_size, file_ptr);
    }

    free(line_buf);
    fclose(file_ptr);
    return (0);
}
