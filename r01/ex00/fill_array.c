/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatyko <omatyko@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:01:13 by omatyko           #+#    #+#             */
/*   Updated: 2024/08/11 21:52:49 by omatyko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#define SIZE 4

// Function to handle when the input is SIZE (4)
void	handle_size_cond(int (*outarr)[SIZE], int i, int j)
{
	int	k;

	k = 0;
	while (k < SIZE)
	{
		if (i == 0)
			outarr[k][j] = k + 1;
		if (i == 1)
			outarr[SIZE - k - 1][j] = k + 1;
		if (i == 2)
			outarr[j][k] = k + 1;
		if (i == 3)
			outarr[j][SIZE - k - 1] = k + 1;
		k++;
	}
}

// Function to handle when the input is 1 (only one element visible)
void	handle_one_cond(int (*outarr)[SIZE], int i, int j)
{
	if (i == 0)
		outarr[0][j] = SIZE;
	if (i == 1)
		outarr[SIZE - 1][j] = SIZE;
	if (i == 2)
		outarr[j][0] = SIZE;
	if (i == 3)
		outarr[j][SIZE - 1] = SIZE;
}

void	zero_fill(int (*outarr)[SIZE])
{
	int	i;
	int	j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			outarr[i][j] = 0 ;
			j++;
		}
		i++;
	}
}

// Function to initialize the output array based on input conditions
void	ini_fill(int (*inarr)[SIZE], int (*outarr)[SIZE])
{
	int	i;
	int	j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			if (inarr[i][j] == SIZE)
			{
				handle_size_cond(outarr, i, j);
			}
			if (inarr[i][j] == 1)
			{
				handle_one_cond(outarr, i, j);
			}
			j++;
		}
		i++;
	}
}
