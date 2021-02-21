/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:41:01 by mifernan          #+#    #+#             */
/*   Updated: 2019/11/29 10:40:45 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_free_tab(char **tab)
{
	int i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			ft_strdel(&tab[i]);
			i++;
		}
		free(tab);
	}
}

int		ft_end_conv(char c)
{
	char	*conv;
	int		i;

	conv = ft_strdup("-0123456789.*");
	i = 0;
	while (conv[i])
	{
		if (c == conv[i])
		{
			ft_strdel(&conv);
			return (1);
		}
		i++;
	}
	ft_strdel(&conv);
	return (0);
}

int		ft_is_conv(char c)
{
	char	*conv;
	int		i;

	conv = ft_strdup("cspdiuxX-0123456789.*");
	i = 0;
	while (conv[i])
	{
		if (c == conv[i])
		{
			ft_strdel(&conv);
			return (1);
		}
		i++;
	}
	ft_strdel(&conv);
	return (0);
}

char	*ft_find_flags(const char *str)
{
	int		i;
	char	*cpy;

	cpy = NULL;
	i = 0;
	while (str[i])
	{
		if ((i != 0) && (str[i - 1] == '%'))
		{
			cpy = ft_strjoin_free(cpy, ft_convert_char(str[i - 1]), 3);
			if (str[i] == '%')
				cpy = ft_strjoin_free(cpy, ft_convert_char(str[i++]), 3);
			else
			{
				while ((ft_end_conv(str[i]) == 1) && str[i])
					cpy = ft_strjoin_free(cpy, ft_convert_char(str[i++]), 3);
				if (ft_is_conv(str[i]) == 1)
					cpy = ft_strjoin_free(cpy, ft_convert_char(str[i++]), 3);
			}
			cpy = ft_strjoin_free(cpy, ft_convert_char(','), 3);
		}
		i++;
	}
	cpy = ft_strjoin_free(cpy, ft_convert_char('\0'), 3);
	return (cpy);
}

char	**ft_split_flags(const char *str)
{
	char	**tab;
	char	*s;

	s = ft_find_flags(str);
	tab = ft_split(s, ',');
	ft_strdel(&s);
	return (tab);
}
