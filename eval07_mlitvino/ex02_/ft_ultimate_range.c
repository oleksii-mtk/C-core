/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:43:18 by mlitvino          #+#    #+#             */
/*   Updated: 2024/08/19 12:09:58 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	size = max - min;
	*range = (int *)malloc(sizeof(int) * size);
	if (*range == 0)
		return (-1);
	i = 0;
	while (i < size)
	{
		range[0][i] = min + 1;
		i++;
	}
	return (size);
}

/*int	main(void)
{
	int	min;
	int	max;
	int		*range;
	

	min = -21;
	max = 0;
	printf("%d", ft_ultimate_range(&range, min, max));
	return (0);
}*/
