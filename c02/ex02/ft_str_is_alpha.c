/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatyko <omatyko@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:52:38 by omatyko           #+#    #+#             */
/*   Updated: 2024/08/06 23:06:51 by omatyko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 65)
			return (0);
		if (str[i] > 90 && str[i] < 97)
			return (0);
		if (str[i] > 122)
			return (0);
		i++;
	}
	return (1);
}
