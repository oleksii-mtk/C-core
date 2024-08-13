/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xho <xho@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:00:08 by xho               #+#    #+#             */
/*   Updated: 2024/08/11 21:46:50 by omatyko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#define SIZE 4

void	print_int(int i)
{
	char	c;
	int		j;

	j = 0;
	if (i >= 10)
	{
		j = i / 10;
		c = '0' + j;
		write(1, &c, 1);
		j = i % 10;
		print_int(j);
	}
	else
	{
		c = '0' + i;
		write(1, &c, 1);
	}
}

void	print_array(int arr[SIZE][SIZE])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			print_int(arr[i][j]);
			if (j < SIZE - 1)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
