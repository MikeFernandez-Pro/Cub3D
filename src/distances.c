/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distances.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 13:04:18 by mifernan          #+#    #+#             */
/*   Updated: 2020/03/03 13:48:35 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_orientation(t_datas *datas, t_player *player)
{
	if (datas->obj_dist == 0)
	{
		if (sin((M_PI / 180) * player->angle) > 0)
			datas->obj_ori = 0;
		else
			datas->obj_ori = 1;
	}
	else
	{
		if (cos((M_PI / 180) * player->angle) > 0)
			datas->obj_ori = 2;
		else
			datas->obj_ori = 3;
	}
}

double	ft_fix_fisheye(t_player *player, double disth)
{
	if (player->angle > player->dir)
		disth *= cos(((M_PI / 180) * player->angle)
		- ((M_PI / 180) * player->dir));
	else if (player->angle < player->dir)
		disth *= cos(((M_PI / 180) * player->dir)
		- ((M_PI / 180) * player->angle));
	return (disth);
}

void	ft_distance_wall(t_player *player, t_datas *datas, t_node *node)
{
	double disth;
	double distv;

	ft_horizontal_check(player, datas, node);
	ft_vertical_check(player, datas, node);
	disth = sqrt(pow((player->x - player->ax), 2) + pow(
		(player->y - player->ay), 2));
	distv = sqrt(pow((player->x - player->bx), 2) + pow(
		(player->y - player->by), 2));
	datas->obj_col = (int)player->ax % (int)player->prec;
	datas->obj_dist = 0;
	if (disth > distv)
	{
		disth = distv;
		datas->obj_col = (int)player->by % (int)player->prec;
		datas->obj_dist = 1;
	}
	disth = ft_fix_fisheye(player, disth);
	ft_orientation(datas, player);
	datas->obj_h = (ceil((player->prec / disth) * (player->dist_proj)));
}

void	ft_distance_sprites(t_player *player, t_node *node)
{
	double		disth;
	double		distv;
	t_sprites	*current;

	current = node->begin;
	while (current)
	{
		disth = -1;
		if (current->cx != -1 && current->cy != -1)
			disth = sqrt(pow((player->x - current->cx), 2) + pow(
			(player->y - current->cy), 2));
		if (current->dx != -1 && current->dy != -1)
			distv = sqrt(pow((player->x - current->dx), 2) + pow(
			(player->y - current->dy), 2));
		current->col = (int)current->cx % (int)player->prec;
		if (disth == -1 || (disth > distv && distv != -1))
		{
			disth = distv;
			current->col = (int)current->dy % (int)player->prec;
		}
		disth = ft_fix_fisheye(player, disth);
		current->height = (ceil((player->prec / disth) * (player->dist_proj)));
		current = current->next;
	}
}
