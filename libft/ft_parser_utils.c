/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:50:32 by mifernan          #+#    #+#             */
/*   Updated: 2019/11/28 15:42:16 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	ft_find_flag(char *str)
{
	int		i;
	int		min;
	int		zero;

	if (!str)
		return ('\0');
	i = 0;
	min = -1;
	zero = -1;
	while (str[i])
	{
		if (str[i] == '-')
			min = 1;
		if ((str[i] == '0') && (ft_is_conv(str[i - 1]) == 0))
			zero = 1;
		i++;
	}
	if (min == 1)
		return ('-');
	if (zero == 1)
		return ('0');
	return ('\0');
}

int		ft_find_pos_prec(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			return (i);
		i++;
	}
	return (-1);
}

int		ft_find_width(char *str, va_list *args)
{
	int		i;
	int		value;
	char	*tab;
	int		j;

	i = 0;
	value = 0;
	while (str[i] != '.' && str[i])
	{
		j = 0;
		if (str[i] == '*')
			value = (va_arg(*args, int));
		else if (ft_isdigit(str[i]) == 1 && (str[i] != '0'))
		{
			tab = ft_calloc(11, sizeof(char));
			while (ft_isdigit(str[i]) == 1 && str[i])
				tab[j++] = str[i++];
			tab[j] = '\0';
			value = (ft_atoi(tab));
			ft_strdel(&tab);
			i--;
		}
		i++;
	}
	return (value);
}

int		ft_find_width_prec(char *str, va_list *args, int i)
{
	int		value;
	char	*tab;
	int		j;

	value = 0;
	while (str[i])
	{
		j = 0;
		if (str[i] == '*')
			value = (va_arg(*args, int));
		else if (ft_isdigit(str[i]) == 1 && (str[i] != '0'))
		{
			if (!(tab = (char*)malloc(sizeof(char) * 11)))
				return (0);
			while (ft_isdigit(str[i]) == 1 && str[i])
				tab[j++] = str[i++];
			tab[j] = '\0';
			value = (ft_atoi(tab));
			ft_strdel(&tab);
			i--;
		}
		i++;
	}
	return (value);
}

int		ft_find_precision(char *str, va_list *args)
{
	int		i;
	int		value;

	if (!str)
		return (0);
	i = ft_find_pos_prec(str);
	if (i == (-1))
		return (-1);
	value = ft_find_width_prec(str, args, i);
	return (value);
}
