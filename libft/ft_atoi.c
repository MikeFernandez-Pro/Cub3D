/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:41:19 by mifernan          #+#    #+#             */
/*   Updated: 2019/10/16 11:35:19 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			minius;
	long long	result;

	i = 0;
	minius = 1;
	result = 0;
	while ((str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r')) && str[i])
		i++;
	if (str[i] == '-')
	{
		minius = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
		if (result < 0)
			return ((minius == 1) ? -1 : 0);
	}
	return ((int)result * minius);
}
