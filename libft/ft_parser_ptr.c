/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:48:45 by mifernan          #+#    #+#             */
/*   Updated: 2019/11/27 17:25:39 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_init_ptrwidth(int width, char *flag, char *cpy)
{
	char	*str;
	int		len;

	str = NULL;
	if (width < 0 && (width != (-1)))
	{
		width *= -1;
		*flag = '-';
	}
	if ((width == -1) || (width <= ft_strlen(cpy)))
		return (NULL);
	len = width - ft_strlen(cpy);
	if (width > 0)
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

int		ft_putptr_c(char *flags, va_list *args)
{
	char	*str;
	char	*cpy;
	int		width;
	char	flag;

	width = ft_find_width(flags, args);
	cpy = ft_convert_ptr(va_arg(*args, long int));
	flag = ft_find_flag(flags);
	str = ft_init_ptrwidth(width, &flag, cpy);
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
