/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:00:09 by mifernan          #+#    #+#             */
/*   Updated: 2020/03/03 13:43:16 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_is_obstacle(t_player *player, t_datas *datas, int key)
{
	if (key == 122)
		if (datas->map[(int)((player->y - (100 * sin((M_PI / 180)
		* player->dir))) / player->prec)][(int)((player->x +
		(100 * cos((M_PI / 180) * player->dir))) / player->prec)] == '1')
			return (1);
	if (key == 113)
		if (datas->map[(int)((player->y - (100 * cos((M_PI / 180)
		* player->dir))) / player->prec)][(int)((player->x -
		(100 * sin((M_PI / 180) * player->dir))) / player->prec)] == '1')
			return (1);
	if (key == 115)
		if (datas->map[(int)((player->y + (100 * sin((M_PI / 180)
		* player->dir))) / player->prec)][(int)((player->x -
		(100 * cos((M_PI / 180) * player->dir))) / player->prec)] == '1')
			return (1);
	if (key == 100)
		if (datas->map[(int)((player->y + (100 * cos((M_PI / 180)
		* player->dir))) / player->prec)][(int)((player->x +
		(100 * sin((M_PI / 180) * player->dir))) / player->prec)] == '1')
			return (1);
	return (0);
}

void	ft_forward(t_player *player, t_datas *datas, int key)
{
	if (key == 122)
	{
		if (ft_is_obstacle(player, datas, key) == 0)
		{
			if (player->y - (100 * sin((M_PI / 180) * player->dir)) > 300
			&& (player->y - (100 * sin((M_PI / 180) * player->dir))
			< (datas->h_map * player->prec) - 300))
				player->y -= 125 * sin((M_PI / 180) * player->dir);
			if (player->x + (100 * cos((M_PI / 180) * player->dir))
			< (datas->l_map[(int)(player->y
			/ player->prec)] * player->prec) - 300
			&& player->x + (100 * cos((M_PI / 180) * player->dir)) > 300)
				player->x += 125 * cos((M_PI / 180) * player->dir);
		}
	}
}

void	ft_left(t_player *player, t_datas *datas, int key)
{
	if (key == 113)
	{
		if (ft_is_obstacle(player, datas, key) == 0)
		{
			if (player->y - (100 * cos((M_PI / 180) * player->dir)) > 300 &&
			(player->y - (100 * cos((M_PI / 180) * player->dir))) <
			(datas->h_map * player->prec) - 300)
				player->y -= 125 * cos((M_PI / 180) * player->dir);
			if (player->x - (100 * sin((M_PI / 180) * player->dir)) > 300 &&
			player->x - (100 * sin((M_PI / 180) * player->dir)) <
			(datas->l_map[(int)(player->y
			/ player->prec)] * player->prec) - 300)
				player->x -= 125 * sin((M_PI / 180) * player->dir);
		}
	}
}

void	ft_backward(t_player *player, t_datas *datas, int key)
{
	if (key == 115)
	{
		if (ft_is_obstacle(player, datas, key) == 0)
		{
			if (player->y + (100 * sin((M_PI / 180) * player->dir)) <
			(datas->h_map * player->prec) - 300 &&
			player->y + (100 * sin((M_PI / 180) * player->dir)) > 300)
				player->y += 125 * sin((M_PI / 180) * player->dir);
			if (player->x - (100 * cos((M_PI / 180) * player->dir)) > 300 &&
			player->x - (100 * cos((M_PI / 180) * player->dir)) <
			(datas->l_map[(int)(player->y
			/ player->prec)] * player->prec) - 300)
				player->x -= 125 * cos((M_PI / 180) * player->dir);
		}
	}
}

void	ft_right(t_player *player, t_datas *datas, int key)
{
	if (key == 100)
	{
		if (ft_is_obstacle(player, datas, key) == 0)
		{
			if (player->y + (100 * cos((M_PI / 180) * player->dir)) <
			(datas->h_map * player->prec) - 300 &&
			player->y + (100 * cos((M_PI / 180) * player->dir)) > 300)
				player->y += 125 * cos((M_PI / 180) * player->dir);
			if (player->x + (100 * sin((M_PI / 180) * player->dir)) <
			(datas->l_map[(int)(player->y
			/ player->prec)] * player->prec) - 300 &&
			player->x + (100 * sin((M_PI / 180) * player->dir)) > 300)
				player->x += 125 * sin((M_PI / 180) * player->dir);
		}
	}
}
