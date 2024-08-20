/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:24:26 by mlitvino          #+#    #+#             */
/*   Updated: 2024/08/18 20:46:40 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*str;
	int	i;

	if (min >= max)
		return (NULL);
	str = malloc(sizeof(int) * ((unsigned int)max - (unsigned int)min + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (min <= max)
	{
		str[i] = min;
		i++;
		min++;
	}
	return (str);
}

/*int	main(void)
{
	int	min;
	int	max;
	int	i;
	int		*str;

	min = -214;
	max = 0;
	i = 0;
	str = ft_range(min, max);
	while (str[i])
	{	
		printf("%d\n", str[i]);
		i++;
	}
	return (0);
}*/
