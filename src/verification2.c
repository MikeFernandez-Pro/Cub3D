/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 13:15:24 by mifernan          #+#    #+#             */
/*   Updated: 2020/03/04 15:05:46 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_find_sprites(char **map)
{
	int i;
	int j;
	int cpt;

	i = 0;
	cpt = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '2')
				cpt++;
			j++;
		}
		i++;
	}
	return (cpt);
}

int		ft_verif_spaces_conform(t_datas *datas, int i, int *j)
{
	int start;
	int end;

	start = 0;
	end = datas->l_map[i] - 1;
	if (datas->map[i][*j] == ' ')
	{
		start = *j;
		while (datas->map[i][*j] == ' ' && *j < datas->l_map[i])
			*j = *j + 1;
		end = *j;
		if ((start > 0 && datas->map[i][start - 1] != '1')
		|| (end < datas->l_map[i] - 1 && datas->map[i][end] != '1'))
			return (-1);
	}
	return (0);
}

int		ft_verif_spaces(t_datas *datas)
{
	int i;
	int j;

	i = -1;
	while (++i < datas->h_map)
	{
		j = 0;
		while (j < datas->l_map[i])
		{
			if (ft_verif_spaces_conform(datas, i, &j) == -1)
				return (-1);
			j++;
		}
	}
	return (1);
}

int		ft_verif_player_pos(t_datas *datas)
{
	int i;
	int j;

	i = 0;
	while (datas->map[i])
	{
		j = 0;
		while (datas->map[i][j])
		{
			if (ft_ispos(datas->map[i][j]) == 1)
			{
				if ((i > 0 && datas->map[i - 1][j] == ' ')
				|| (j > 0 && datas->map[i][j - 1] == ' ')
				|| (i < datas->h_map - 2 && datas->map[i + 1][j] == ' ')
				|| (j < datas->l_map[i] - 2 && datas->map[i][j + 1] == ' '))
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_global_verif(t_datas *datas)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (!datas->texts[i].str)
			return (-1);
		i++;
	}
	if (datas->res[0] < 300 || datas->res[0] > 3840
	|| datas->res[1] < 300 || datas->res[1] > 2160)
	{
		datas->res[0] = 1280;
		datas->res[1] = 800;
	}
	return (0);
}
