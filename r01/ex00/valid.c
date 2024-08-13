/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatyko <omatyko@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 22:38:51 by omatyko           #+#    #+#             */
/*   Updated: 2024/08/11 23:01:19 by omatyko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#define SIZE 4

int	parse_number(char **ptr)
{
	int	num;

	num = 0;
	while (**ptr >= '0' && **ptr <= '9')
	{
		num = num * 10 + (**ptr - '0');
		(*ptr)++;
	}
	return (num);
}

int	fill_idata_from_input(char *input, int idata[SIZE][SIZE])
{
	int		i;
	int		num;
	char	*ptr;

	i = 0;
	ptr = input;
	while (i < SIZE * SIZE)
	{
		while (*ptr == ' ')
			ptr++;
		num = parse_number(&ptr);
		if (num < 1 || num > 4)
			return (write(1, "Error\n", 6));
		idata[i / SIZE][i % SIZE] = num;
		i++;
	}
	if (*ptr != '\0' || i != SIZE * SIZE)
		return (write(1, "Error\n", 6));
	return (0);
}
