/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatyko <omatyko@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:52:38 by omatyko           #+#    #+#             */
/*   Updated: 2024/08/07 23:08:41 by omatyko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 64 && str[i] < 91)
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

int	is_abn(char c)
{
	if ((c > 47 && c < 58) || (c > 96 && c < 123))
		return (1);
	else
		return (0);
}

int	is_num(char c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	char	*l_str;
	int		i;
	int		ws;

	l_str = ft_strlowcase(str);
	ws = 1;
	i = 0;
	while (l_str[i] != '\0')
	{
		if (ws == 1 && is_abn(l_str[i]) == 1)
		{
			if (is_num(l_str[i]) == 0)
				l_str[i] = l_str[i] - 32;
			ws = 0;
		}
		else
			if (is_abn(l_str[i]) == 0)
				ws = 1;
		i++;
	}
	return (l_str);
}
