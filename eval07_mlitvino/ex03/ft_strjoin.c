/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:18:43 by mlitvino          #+#    #+#             */
/*   Updated: 2024/08/19 16:20:15 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_count_length(int size, int *l, char **strs, char *sep)
{
	int	c;
	int	i;

	c = 0;
	i = 0;
	while (sep[i])
	{
		(*l)++;
		i++;
	}
	*l = *l * (size - 1);
	while (c < size)
	{
		i = 0;
		while (strs[c][i])
		{
			(*l)++;
			i++;
		}
		c++;
	}
	return (*l);
}

char	*ft_putsep(char *ar, char **strs, char *sep, int size)
{
	int	i;
	int	m;
	int	c;

	c = 0;
	i = 0;
	while (c < size)
	{
		m = 0;
		while (strs[c][m])
			ar[i++] = strs[c][m++];
		m = 0;
		while (sep[m] && c < size - 1)
			ar[i++] = sep[m++];
		c++;
	}
	ar[i] = '\0';
	return (ar);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		l;
	char	*ar;

	l = 0;
	ar = (char *)malloc(sizeof(char));
	if (size <= 0)
		return (ar);
	ft_count_length(size, &l, strs, sep);
	ar = (char *)malloc(sizeof(char) * l + 2);
	ft_putsep(ar, strs, sep, size);
	return (ar);
}

/*int	main(void)
{
	int	size = 3;
	char	*sep = "aa";
	char	*strs[] = {"bb", "tt", "ff"};

	printf("%s", ft_strjoin(size, strs, sep));
	return (0);
}*/
