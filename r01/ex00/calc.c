/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatyko <omatyko@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:06:05 by omatyko           #+#    #+#             */
/*   Updated: 2024/08/11 22:24:36 by omatyko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#define SIZE 4

int	search_using_idata(int (*idata)[4], int *aset, int row, int col)
{
	int	value;
	int	i;

	i = SIZE;
	while (i > 0)
	{
		value = aset[i - 1];
		if (value > 0)
		{
			if (value <= col + 1 + SIZE - idata[2][row] &&
				value <= SIZE + idata[3][row] &&
				value <= row + 1 + SIZE - idata[0][col] &&
				value <= SIZE + idata[1][col])
				return (value);
		}
		i--;
	}
	return (0);
}

int	find_new_value(int (*idata)[4], int (*odata)[4], int row, int col)
{
	int	i;
	int	aset[4];

	i = 0;
	while (i < 4)
	{
		aset[i] = i + 1;
		i++;
	}
	i = 0;
	while (i < SIZE)
	{
		if (odata[row][i] > 0)
			aset[odata[row][i] - 1] = 0;
		if (odata[i][col] > 0)
			aset[odata[i][col] - 1] = 0;
		i++;
	}
	return (search_using_idata(idata, aset, row, col));
}

// Function to find the next value and handle potential errors
int	find_and_set_value(int (*idata)[4], int (*odata)[4], int row, int col)
{
	int	value;

	value = find_new_value(idata, odata, row, col);
	if (value == 0)
	{
		if (row != 1 && (odata[row - 1][col] - 1) > 0)
		{
			odata[row - 1][col]--;
			value = find_new_value(idata, odata, row, col);
			if (value == 0)
			{
				return (1);
			}
		}
	}
	odata[row][col] = value;
	return (0);
}

// Function to handle an individual cell
int	process_cell(int (*idata)[4], int (*odata)[4], int row, int col)
{
	if (odata[row][col] == 0)
	{
		if (find_and_set_value(idata, odata, row, col) != 0)
		{
			return (1);
		}
	}
	return (0);
}

// Main function to fill the data in the grid
int	fill_data(int (*idata)[4], int (*odata)[4])
{
	int	row;
	int	col;

	col = 0;
	while (col < 4)
	{
		row = 0;
		while (row < 4)
		{
			if (process_cell(idata, odata, row, col) != 0)
			{
				return (1);
			}
			row++;
		}
		col++;
	}
	return (0);
}
