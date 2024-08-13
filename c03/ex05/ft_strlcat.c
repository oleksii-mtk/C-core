/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatyko <omatyko@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:52:53 by omatyko           #+#    #+#             */
/*   Updated: 2024/08/12 17:06:28 by omatyko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	total;
	char			*ptr;
	int				i;

	i = 0;
	total = 0;
	ptr = dest;
	while (*ptr != '\0')
	{
		total++;
		ptr++;
	}
	while (i < size && *src != '\0')
	{
		*ptr = *src;
		src++;
		ptr++;
		total++;
		i++;
	}
	*ptr = '\0';
	return (total);
}
