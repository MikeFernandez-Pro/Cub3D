/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:16:27 by mifernan          #+#    #+#             */
/*   Updated: 2020/03/04 15:04:35 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_size_lines(t_datas *datas)
{
	int i;

	i = 0;
	if (!(datas->l_map = malloc(sizeof(int)
	* (ft_tablen(datas->map) + 1))))
		return ;
	while (datas->map[i])
	{
		datas->l_map[i] = ft_strlen(datas->map[i]);
		i++;
	}
	datas->l_map[i] = '\0';
}

int		ft_verif_walls(t_datas *datas)
{
	int i;
	int j;

	ft_size_lines(datas);
	i = 1;
	while (i < datas->h_map - 2)
	{
		j = 0;
		while (datas->map[i][j])
		{
			if (datas->map[i][j] == '0' && ((ft_strlen(datas->map[i - 1])
			<= j + 1) || (ft_strlen(datas->map[i + 1]) <= j + 1)))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_verification_map(t_datas *datas)
{
	int i;
	int j;
	int cpt;

	i = -1;
	cpt = 0;
	while (datas->map[++i])
	{
		j = -1;
		while (datas->map[i][++j])
			if (ft_ispos(datas->map[i][j]) == 1)
				cpt++;
		if ((datas->map[i][0] != '1' && datas->map[i][0] != ' ')
		|| (datas->map[i][j - 1] != '1' && datas->map[i][j - 1] != ' '))
			return (-1);
	}
	datas->nb_sprites = ft_find_sprites(datas->map);
	if (cpt != 1 || ft_fstlst(datas) == -1 || ft_verif_walls(datas) == -1
	|| ft_verif_spaces(datas) == -1 || ft_verif_player_pos(datas) == -1
	|| ft_global_verif(datas) == -1)
		return (-1);
	return (0);
}

int		ft_fstlst(t_datas *datas)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (datas->map[0][j])
	{
		if (datas->map[0][j] != '1' && datas->map[0][j] != ' ')
			return (-1);
		j++;
	}
	while (datas->map[i])
		i++;
	datas->h_map = i;
	i--;
	j = 0;
	while (datas->map[i][j])
	{
		if (datas->map[i][j] != '1' && datas->map[i][j] != ' ')
			return (-1);
		j++;
	}
	return (0);
}
