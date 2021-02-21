/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:30:05 by mifernan          #+#    #+#             */
/*   Updated: 2020/03/03 13:45:20 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_player_pos(t_player *player, char **map)
{
	int i;
	int j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_ispos(map[i][j]) == 1)
			{
				player->x = j * player->prec + (player->prec / 2);
				player->y = i * player->prec + (player->prec / 2);
				player->dir = ft_direction(map[i][j]);
				player->angle = player->dir + (player->fov / 2);
			}
		}
	}
}

void	ft_horizontal_check(t_player *player, t_datas *datas, t_node *node)
{
	player->ya = -player->prec;
	player->xa = 1;
	if (sin((M_PI / 180) * player->angle) > 0)
		player->ay = (int)(player->y / player->prec) * (player->prec) - 0.00001;
	else if (sin((M_PI / 180) * player->angle) < 0)
	{
		player->ay = (int)(player->y / player->prec)
		* (player->prec) + player->prec;
		player->ya = player->prec;
		player->xa = -1;
	}
	player->ax = (player->x + (player->y - player->ay)
	/ tan((M_PI / 180) * player->angle));
	player->xa *= player->prec / tan((M_PI / 180) * player->angle);
	ft_horizontal_obst(datas, player, node);
}

void	ft_horizontal_obst(t_datas *datas, t_player *player, t_node *node)
{
	t_sprites *current;

	current = node->begin;
	while ((int)(player->ax / player->prec) >= 0
	&& (int)(player->ay / player->prec) >= 0
	&& (int)(player->ax / player->prec) <
	datas->l_map[(int)(player->ay / player->prec)]
	&& (int)(player->ay / player->prec) < datas->h_map)
	{
		if (datas->map[(int)(player->ay / player->prec)]
		[(int)(player->ax / player->prec)] == '1')
			return ;
		if (datas->map[(int)(player->ay / player->prec)]
		[(int)(player->ax / player->prec)] == '2'
		&& ((sin((M_PI / 180) * player->dir) > 0.707107
		&& fabs(cos((M_PI / 180) * player->dir)) < 0.707107)
		|| (sin((M_PI / 180) * player->dir) < -0.707107
		&& fabs(cos((M_PI / 180) * player->dir)) < 0.707107)))
		{
			ft_hor_value(current, player);
			current = current->next;
		}
		player->ax += player->xa;
		player->ay += player->ya;
	}
}

void	ft_vertical_check(t_player *player, t_datas *datas, t_node *node)
{
	player->xb = player->prec;
	player->yb = -1;
	if (cos((M_PI / 180) * player->angle) > 0)
		player->bx = (int)(player->x / player->prec)
		* (player->prec) + player->prec;
	else if (cos((M_PI / 180) * player->angle) < 0)
	{
		player->bx = (int)(player->x / player->prec)
		* (player->prec) - 0.00001;
		player->xb = -player->prec;
		player->yb = 1;
	}
	player->by = player->y + (player->x - player->bx)
	* tan((M_PI / 180) * player->angle);
	player->yb *= player->prec * tan((M_PI / 180) * player->angle);
	ft_vertical_obst(datas, player, node);
}

void	ft_vertical_obst(t_datas *datas, t_player *player, t_node *node)
{
	t_sprites *current;

	current = node->begin;
	while ((int)(player->bx / player->prec) >= 0
	&& (int)(player->by / player->prec) >= 0
	&& (int)(player->bx / player->prec)
	< datas->l_map[(int)(player->by / player->prec)]
	&& (int)(player->by / player->prec) < datas->h_map)
	{
		if (datas->map[(int)(player->by / player->prec)]
		[(int)(player->bx / player->prec)] == '1')
			return ;
		if (datas->map[(int)(player->by / player->prec)]
		[(int)(player->bx / player->prec)] == '2'
		&& ((cos((M_PI / 180) * player->dir) > 0.707107
		&& fabs(sin((M_PI / 180) * player->dir)) < 0.707107)
		|| (cos((M_PI / 180) * player->dir) < -0.707107
		&& fabs(sin((M_PI / 180) * player->dir)) < 0.707107)))
		{
			ft_ver_value(current, player);
			current = current->next;
		}
		player->bx += player->xb;
		player->by += player->yb;
	}
}
