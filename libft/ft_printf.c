/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:14:48 by mifernan          #+#    #+#             */
/*   Updated: 2019/11/27 17:25:33 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_putpercent_c(char *flags, va_list *args)
{
	char	*str;
	char	*cpy;
	int		width;
	char	flag;

	width = ft_find_width(flags, args);
	cpy = ft_convert_char('%');
	flag = ft_find_flag(flags);
	str = ft_init_charwidth(width, &flag);
	if (flag == '-' && (str != NULL))
		cpy = ft_strjoin_free(cpy, str, 1);
	else if (str != NULL)
		cpy = ft_strjoin_free(str, cpy, 2);
	ft_putstr_fd(cpy, 1);
	width = ft_strlen(cpy);
	if (cpy[0] == '\0')
		width++;
	ft_strdel(&str);
	ft_strdel(&cpy);
	return (width);
}

int		ft_putconv(char *flags, va_list *args)
{
	if (flags[ft_strlen(flags) - 1] == 's')
		return (ft_putstr_c(flags, args));
	if (flags[ft_strlen(flags) - 1] == 'c')
		return (ft_putchar_c(flags, args));
	if (flags[ft_strlen(flags) - 1] == 'd')
		return (ft_putd_c(flags, args));
	if (flags[ft_strlen(flags) - 1] == 'i')
		return (ft_putd_c(flags, args));
	if (flags[ft_strlen(flags) - 1] == 'u')
		return (ft_putu_c(flags, args));
	if (flags[ft_strlen(flags) - 1] == 'x')
		return (ft_putxmin_c(flags, args));
	if (flags[ft_strlen(flags) - 1] == 'X')
		return (ft_putxmaj_c(flags, args));
	if (flags[ft_strlen(flags) - 1] == 'p')
		return (ft_putptr_c(flags, args));
	if (flags[ft_strlen(flags) - 1] == '%')
		return (ft_putpercent_c(flags, args));
	return (0);
}

int		ft_printf(const	char *src, ...)
{
	va_list	args;
	char	**flags;
	int		cpt;

	va_start(args, src);
	flags = ft_split_flags(src);
	cpt = ft_while_printf(src, flags, &args);
	ft_free_tab(flags);
	va_end(args);
	if (cpt < 0)
		return (0);
	return (cpt);
}
