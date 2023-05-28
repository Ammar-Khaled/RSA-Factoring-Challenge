#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
	char *line;
	long long number;

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

	line = malloc(1024 * sizeof(char));
	if (!line)
	{
		fprintf(stderr, "Allocation erroe\n");
		exit(EXIT_FAILURE);
	}

	line = fgets(line, 1025, file_ptr);
	while (line)
	{
		number = atoll(line);
		if (number % 2 == 0)
		{
			printf("%lli=%i*%lli\n", number, 2, number / 2);
		}
		else
		{
			for (long long i = 3; i < number; i++)
			{
				if (number % i == 0)
				{
					printf("%lli=%lli*%lli\n", number, i, number / i);
				}
			}
		}

		line = fgets(line, 1025, file_ptr);
	}

	free(line);
	fclose(file_ptr);
	return (0);
}
