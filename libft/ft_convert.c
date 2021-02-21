/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:28:07 by mifernan          #+#    #+#             */
/*   Updated: 2019/11/26 17:12:47 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_convert_d(long int nb)
{
	char	*str;
	int		i;
	int		neg;

	neg = 0;
	i = ft_numlen(nb, 10);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	if (nb < 0)
	{
		neg = 1;
		str[0] = '-';
		nb *= -1;
	}
	while (i >= neg)
	{
		if ((nb % 10) > 9)
			str[i] = (nb % 10) + 87;
		else
			str[i] = (nb % 10) + 48;
		nb /= 10;
		i--;
	}
	return (str);
}

char	*ft_convert_ptr(long int nb)
{
	char	*str;
	int		i;

	i = ft_numlen(nb, 16) + 2;
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	str[0] = '0';
	while (i >= 0)
	{
		if ((nb % 16) > 9)
			str[i] = (nb % 16) + 87;
		else
			str[i] = (nb % 16) + 48;
		nb /= 16;
		if (i == 1)
			str[i] = 'x';
		i--;
	}
	return (str);
}

char	*ft_convert_xmin(long int nb)
{
	char	*str;
	int		i;
	int		neg;

	neg = 0;
	if (nb < 0)
		nb = ft_convert_ld(nb);
	i = ft_numlen(nb, 16);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	while (i >= neg)
	{
		if ((nb % 16) > 9)
			str[i] = (nb % 16) + 87;
		else
			str[i] = (nb % 16) + 48;
		nb /= 16;
		i--;
	}
	return (str);
}

char	*ft_convert_xmaj(long int nb)
{
	char	*str;
	int		i;
	int		neg;

	neg = 0;
	if (nb < 0)
		nb = ft_convert_ld(nb);
	i = ft_numlen(nb, 16);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	while (i >= neg)
	{
		if ((nb % 16) > 9)
			str[i] = (nb % 16) + 55;
		else
			str[i] = (nb % 16) + 48;
		nb /= 16;
		i--;
	}
	return (str);
}

char	*ft_convert_u(long int nb)
{
	char	*str;
	int		i;
	int		neg;

	neg = 0;
	if (nb < 0)
		nb = ft_convert_ld(nb);
	i = ft_numlen(nb, 10);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	while (i >= neg)
	{
		if ((nb % 10) > 9)
			str[i] = (nb % 10) + 55;
		else
			str[i] = (nb % 10) + 48;
		nb /= 10;
		i--;
	}
	return (str);
}
