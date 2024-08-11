int	parse_number(char **ptr)
{
	int	num = 0;

	while (**ptr >= '0' && **ptr <= '9')
	{
		num = num * 10 + (**ptr - '0');
		(*ptr)++;
	}
	return (num);
}

int	fill_idata_from_input(char *input, int idata[SIZE][SIZE])
{
	int		i = 0;
	int		num;
	char	*ptr = input;

	while (i < SIZE * SIZE)
	{
		while (*ptr == ' ')
			ptr++;
		if ((num = parse_number(&ptr)) < 1 || num > 4)
			return (write(2, "Error: Invalid value.\n", 22));
		idata[i / SIZE][i % SIZE] = num;
		i++;
	}
	if (*ptr != '\0' || i != SIZE * SIZE)
		return (write(2, "Error: Incorrect number of values.\n", 35));
	return (0);
}

