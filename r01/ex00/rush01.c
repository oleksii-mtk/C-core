/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatyko <omatyko@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:49:21 by omatyko           #+#    #+#             */
/*   Updated: 2024/08/11 23:05:14 by omatyko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define SIZE 4

void	ini_fill(int (*inarr)[SIZE], int (*outarr)[SIZE]);
int		fill_data(int (*idata)[4], int (*odata)[4]);
int		fill_idata_from_input(char *input, int idata[SIZE][SIZE]);
void	print_array(int arr[SIZE][SIZE]);
void	zero_fill(int (*outarr)[SIZE]);

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	main(int argc, char *argv[])
{
	int		idata[4][4];
	int		odata[4][4];

	zero_fill(odata);
	if (argc != 2)
	{
		ft_putstr("Error\n");
		return (1);
	}
	if (fill_idata_from_input(argv[1], idata) != 0)
		return (1);
	ini_fill(idata, odata);
	if (fill_data(idata, odata) == 0)
		print_array(odata);
	else
	{
		ft_putstr("Error\n");
		return (1);
	}
	return (0);
}
