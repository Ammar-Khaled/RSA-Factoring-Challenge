#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <math.h>
#include <string.h>

#define ld long double

int is_divisible(ld num1, ld num2)
{
    ld quotient = num1 / num2;
    return quotient == floorl(quotient); // if quotient is integer
}


int is_prime(ld number)
{
    if (number == 2)
    {
        return 1;
    }

    if (is_divisible(number, 2))
    {
        return 0;
    }

    for (ld i = 3; i < sqrtl(number); i += 2)
    {
        if (is_divisible(number, i))
        {
            return 0;
        }
    }

    return 1;
}

void prime_factoring(ld number)
{
    if (is_divisible(number, 2) && is_prime(number / 2))
    {
        printf("%.0Lf=%.0Lf*%i\n", number, number / 2, 2);
    }
    else
    {
        for (ld i = 3; i < sqrtl(number); i += 2)
        {
            if (is_divisible(number, i) && is_prime(i) && is_prime(number / i))
            {
                printf("%.0Lf=%.0Lf*%.0Lf\n", number, number / i, i);
                break;
            }
        }
    }
}

/**
 * main - Factorizes the number to two prime numbers if possible
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
    ld number;
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
        prime_factoring(number);
        n_read = getline(&line_buf, &buf_size, file_ptr);
    }

    free(line_buf);
    fclose(file_ptr);
    return (0);
}
