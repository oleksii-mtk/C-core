/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 11:46:18 by mlitvino          #+#    #+#             */
/*   Updated: 2024/08/16 12:26:19 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		l;
	int		i;
	char	*dest;

	l = 0;
	i = 0;
	while (src[l])
		l++;
	dest = malloc(sizeof(char) * (l + 1));
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*int	main(void)
{
	char	*src = "123456"; 
	ft_strdup(src);
	printf("%s", ft_strdup(src));
	return (0);
}*/
