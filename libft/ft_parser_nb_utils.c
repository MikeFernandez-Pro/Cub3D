/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_nb_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:47:50 by mifernan          #+#    #+#             */
/*   Updated: 2019/11/29 10:42:34 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_isneg(char *cpy)
{
	int		i;

	i = 0;
	while (cpy[i])
	{
		if (cpy[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_find_pos_neg(char *cpy)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((cpy[i] != '-') && cpy[i])
		i++;
	if (cpy[i] != '-')
		return (cpy);
	if (ft_strlen(cpy) >= 3)
	{
		while ((cpy[j] != '0') && cpy[j])
			j++;
	}
	if ((ft_strlen(cpy) >= 3) && cpy[j] == '0')
	{
		if (ft_isdigit(cpy[j - 1]) == 0)
		{
			cpy[i] = '0';
			cpy[j] = '-';
		}
	}
	return (cpy);
}

char	*ft_init_dprec(int prec, char *cpy, char *flag)
{
	char	*str;
	int		len;

	str = NULL;
	if ((prec > 0 && (prec < ft_strlen(cpy))) || ((prec < 0)))
		return (NULL);
	if ((prec == 0) && (*flag == '0'))
		*flag = '\0';
	else if (prec > ft_strlen(cpy))
		*flag = '0';
	if (ft_isneg(cpy) == 1)
		len = (prec - ft_strlen(cpy)) + 1;
	else
		len = (prec - ft_strlen(cpy));
	if (len > 0)
	{
		if (!(str = (char*)malloc(sizeof(char) * len + 1)))
			return (NULL);
		str[len] = '\0';
		if (*flag == '0' || (ft_isneg(cpy) == 1))
			str = ft_memset(str, '0', len);
		else
			str = ft_memset(str, ' ', len);
	}
	return (str);
}

char	*ft_init_dwidth(int width, char *cpy, char *flag, int prec)
{
	char	*str;
	int		len;

	str = NULL;
	if (width < 0)
	{
		width *= -1;
		*flag = '-';
	}
	if ((width == 0) || (width >= 0 && width <= ft_strlen(cpy))
	|| (width == (-1)) || ((prec > width) && (width > (-1)))
	|| ((ft_isneg(cpy) == 1) && (width <= ft_strlen(cpy))))
		return (NULL);
	if (prec > ft_strlen(cpy))
		len = ((width - ft_strlen(cpy)) + (prec - ft_strlen(cpy)));
	else
		len = (width - ft_strlen(cpy));
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	if (prec < 0 && *flag == '0')
		str = ft_memset(str, '0', len);
	else
		str = ft_memset(str, ' ', len);
	return (str);
}
