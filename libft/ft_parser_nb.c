/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:42:34 by mifernan          #+#    #+#             */
/*   Updated: 2019/11/29 10:46:13 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_prec_zero(char *cpy, int prec)
{
	if (cpy[0] == '0' && prec == 0)
	{
		ft_strdel(&cpy);
		cpy = ft_strdup("\0");
	}
	return (cpy);
}

int		ft_putd_c(char *flags, va_list *args)
{
	char	*str;
	char	*cpy;
	int		width;
	int		prec;
	char	flag;

	width = ft_find_width(flags, args);
	prec = ft_find_precision(flags, args);
	cpy = ft_convert_d(va_arg(*args, int));
	cpy = ft_prec_zero(cpy, prec);
	flag = ft_find_flag(flags);
	str = ft_init_dprec(prec, cpy, &flag);
	cpy = ft_strjoin_free(str, cpy, 3);
	flag = ft_find_flag(flags);
	str = ft_init_dwidth(width, cpy, &flag, prec);
	if ((flag == '-') && (str != NULL))
		cpy = ft_strjoin_free(cpy, str, 1);
	else if (str != NULL)
		cpy = ft_strjoin_free(str, cpy, 2);
	cpy = ft_find_pos_neg(cpy);
	ft_putstr_fd(cpy, 1);
	width = ft_strlen(cpy);
	ft_strdel(&str);
	ft_strdel(&cpy);
	return (width);
}

int		ft_putu_c(char *flags, va_list *args)
{
	char	*str;
	char	*cpy;
	int		width;
	int		prec;
	char	flag;

	width = ft_find_width(flags, args);
	prec = ft_find_precision(flags, args);
	cpy = ft_convert_u(va_arg(*args, int));
	cpy = ft_prec_zero(cpy, prec);
	flag = ft_find_flag(flags);
	str = ft_init_dprec(prec, cpy, &flag);
	cpy = ft_strjoin_free(str, cpy, 3);
	flag = ft_find_flag(flags);
	str = ft_init_dwidth(width, cpy, &flag, prec);
	if ((flag == '-') && (str != NULL))
		cpy = ft_strjoin_free(cpy, str, 1);
	else if (str != NULL)
		cpy = ft_strjoin_free(str, cpy, 2);
	cpy = ft_find_pos_neg(cpy);
	ft_putstr_fd(cpy, 1);
	width = ft_strlen(cpy);
	ft_strdel(&str);
	ft_strdel(&cpy);
	return (width);
}

int		ft_putxmin_c(char *flags, va_list *args)
{
	char	*str;
	char	*cpy;
	int		width;
	int		prec;
	char	flag;

	width = ft_find_width(flags, args);
	prec = ft_find_precision(flags, args);
	cpy = ft_convert_xmin(va_arg(*args, int));
	cpy = ft_prec_zero(cpy, prec);
	flag = ft_find_flag(flags);
	str = ft_init_dprec(prec, cpy, &flag);
	cpy = ft_strjoin_free(str, cpy, 3);
	flag = ft_find_flag(flags);
	str = ft_init_dwidth(width, cpy, &flag, prec);
	if ((flag == '-') && (str != NULL))
		cpy = ft_strjoin_free(cpy, str, 1);
	else if (str != NULL)
		cpy = ft_strjoin_free(str, cpy, 2);
	cpy = ft_find_pos_neg(cpy);
	ft_putstr_fd(cpy, 1);
	width = ft_strlen(cpy);
	ft_strdel(&str);
	ft_strdel(&cpy);
	return (width);
}

int		ft_putxmaj_c(char *flags, va_list *args)
{
	char	*str;
	char	*cpy;
	int		width;
	int		prec;
	char	flag;

	width = ft_find_width(flags, args);
	prec = ft_find_precision(flags, args);
	cpy = ft_convert_xmaj(va_arg(*args, int));
	cpy = ft_prec_zero(cpy, prec);
	flag = ft_find_flag(flags);
	str = ft_init_dprec(prec, cpy, &flag);
	cpy = ft_strjoin_free(str, cpy, 3);
	flag = ft_find_flag(flags);
	str = ft_init_dwidth(width, cpy, &flag, prec);
	if ((flag == '-') && (str != NULL))
		cpy = ft_strjoin_free(cpy, str, 1);
	else if (str != NULL)
		cpy = ft_strjoin_free(str, cpy, 2);
	cpy = ft_find_pos_neg(cpy);
	ft_putstr_fd(cpy, 1);
	width = ft_strlen(cpy);
	ft_strdel(&str);
	ft_strdel(&cpy);
	return (width);
}
