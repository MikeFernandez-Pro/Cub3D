/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:48:49 by mifernan          #+#    #+#             */
/*   Updated: 2019/11/28 14:50:25 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_init_strwidth(int width, char *cpy, char *flag)
{
	char	*str;
	int		len;

	str = NULL;
	if (width > 0 && (width <= ft_strlen(cpy)))
		return (NULL);
	if (width < 0)
	{
		width *= -1;
		*flag = '-';
	}
	len = (width - ft_strlen(cpy));
	if (width > ft_strlen(cpy))
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

char	*ft_init_pustr(char *cpy, int prec)
{
	char *tmp;

	if (cpy == NULL)
	{
		ft_strdel(&cpy);
		cpy = ft_strdup("(null)");
	}
	if (prec == 0)
	{
		ft_strdel(&cpy);
		cpy = ft_strdup("\0");
	}
	else if ((prec > 0) && (prec < ft_strlen(cpy)))
	{
		tmp = ft_strdup(cpy);
		ft_strdel(&cpy);
		cpy = ft_strndup_free(tmp, prec);
		ft_strdel(&tmp);
	}
	return (cpy);
}
