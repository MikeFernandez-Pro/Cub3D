/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:16:10 by mifernan          #+#    #+#             */
/*   Updated: 2020/03/03 13:17:44 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_del_spc(char *str)
{
	int		i;
	int		j;
	char	*cpy;

	i = 0;
	j = 0;
	if (!(cpy = malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	while (str[i])
	{
		if (str[i] != ' ')
			cpy[j++] = str[i];
		i++;
	}
	cpy[j] = '\0';
	return (cpy);
}

int		ft_del_space_start(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' && str[i])
		i++;
	return (i);
}

int		ft_ispos(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (-1);
}

double	ft_direction(char c)
{
	if (c == 'N')
		return (90);
	if (c == 'S')
		return (270);
	if (c == 'E')
		return (0);
	if (c == 'W')
		return (180);
	return (-1);
}

int		ft_tablen(char **str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
