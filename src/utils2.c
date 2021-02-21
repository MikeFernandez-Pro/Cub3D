/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 13:21:25 by mifernan          #+#    #+#             */
/*   Updated: 2020/03/04 10:29:58 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_is_texture(char *str)
{
	if (!str)
		return (-1);
	if (str[0] == 'N')
		return (0);
	else if (ft_strlen(str) >= 2 && str[0] == 'S' && str[1] == 'O')
		return (1);
	else if (str[0] == 'W')
		return (2);
	else if (str[0] == 'E')
		return (3);
	else if (str[0] == 'S')
		return (4);
	return (-1);
}

void	ft_init_lines(char **line, char **cpy_map)
{
	*line = NULL;
	*cpy_map = NULL;
}
