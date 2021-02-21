/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:26:56 by mifernan          #+#    #+#             */
/*   Updated: 2019/11/30 09:24:00 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_putstr_c(char *flags, va_list *args)
{
	char	*str;
	char	*cpy;
	int		width;
	int		prec;
	char	flag;

	width = ft_find_width(flags, args);
	prec = ft_find_precision(flags, args);
	cpy = ft_strdup(va_arg(*args, char *));
	flag = ft_find_flag(flags);
	cpy = ft_init_pustr(cpy, prec);
	str = ft_init_strwidth(width, cpy, &flag);
	if (flag == '-' && (str != NULL))
		cpy = ft_strjoin_free(cpy, str, 1);
	else if (str != NULL)
		cpy = ft_strjoin_free(str, cpy, 2);
	ft_putstr_fd(cpy, 1);
	width = ft_strlen(cpy);
	ft_strdel(&str);
	ft_strdel(&cpy);
	return (width);
}

char	*ft_convert_char(int c)
{
	char	*cpy;

	if (!(cpy = (char*)malloc(sizeof(char) + 1)))
		return (NULL);
	cpy[0] = c;
	cpy[1] = '\0';
	return (cpy);
}

char	*ft_init_charwidth(int width, char *flag)
{
	char	*str;
	int		len;

	str = NULL;
	if (width == -1)
		return (NULL);
	if (width < 0)
	{
		width *= -1;
		*flag = '-';
	}
	len = width - 1;
	if (width > 1)
	{
		if (!(str = (char*)malloc(sizeof(char) * len + 1)))
			return (NULL);
		str[len] = '\0';
		if (*flag == '0')
			str = ft_memset(str, '0', len);
		else
			str = ft_memset(str, ' ', len);
	}
	return (str);
}

int		ft_put_backzero(char *str, int width, char flag)
{
	if (flag == '-' && (str != NULL))
	{
		ft_putchar_fd('\0', 1);
		ft_putstr_fd(str, 1);
	}
	else if (str != NULL)
	{
		ft_putstr_fd(str, 1);
		ft_putchar_fd('\0', 1);
	}
	else
		ft_putchar_fd('\0', 1);
	width = ft_strlen(str);
	width++;
	ft_strdel(&str);
	return (width);
}

int		ft_putchar_c(char *flags, va_list *args)
{
	char	*str;
	char	cpy;
	int		width;
	char	flag;

	width = ft_find_width(flags, args);
	cpy = va_arg(*args, int);
	flag = ft_find_flag(flags);
	str = ft_init_charwidth(width, &flag);
	if (cpy == '\0')
		return (ft_put_backzero(str, width, flag));
	if (flag == '-' && (str != NULL))
		str = ft_strjoin_free(ft_convert_char(cpy), str, 3);
	else if (str != NULL)
		str = ft_strjoin_free(str, ft_convert_char(cpy), 3);
	else
		str = ft_convert_char(cpy);
	ft_putstr_fd(str, 1);
	width = ft_strlen(str);
	ft_strdel(&str);
	return (width);
}
