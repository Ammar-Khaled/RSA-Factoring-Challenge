#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <math.h>
#include <string.h>

#define ld long double

/**
 * is_divisible - checks whether num1 is divisible by num2
 * @num1: first number
 * @num2: second number
 *
 * Return: 1 if divisible, 0 if not
*/
int is_divisible(ld num1, ld num2)
{
	ld quotient;

	quotient = num1 / num2;
	return (quotient == floorl(quotient));    /* if quotient is integer */
}

/**
 * normal_factoring - factorize number into two smaller normal number
 * @number: numebrto be factorized
 *
 */
void normal_factoring(ld number)
{
	if (is_divisible(number, 2))
	{
		printf("%.0Lf=%.0Lf*%i\n", number, number / 2, 2);
	}
	else
	{
		for (ld i = 3; i < sqrtl(number); i += 2)
		{
			if (is_divisible(number, i))
			{
				printf("%.0Lf=%.0Lf*%.0Lf\n", number, number / i, i);
				break;
			}
		}
	}
}

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
		normal_factoring(number);
		n_read = getline(&line_buf, &buf_size, file_ptr);
	}

	free(line_buf);
	fclose(file_ptr);
	return (0);
}
