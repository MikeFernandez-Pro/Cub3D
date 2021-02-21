/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:38:00 by mifernan          #+#    #+#             */
/*   Updated: 2019/11/25 11:50:51 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_numlen(long int nb, int base)
{
	int i;

	if (base < 1 || base > 16)
		return (0);
	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		i++;
	while (nb != 0)
	{
		nb /= base;
		i++;
	}
	return (i);
}

long int	ft_convert_ld(long int nb)
{
	if (nb < 0)
		nb = 4294967295 - (nb * -1) + 1;
	return (nb);
}
