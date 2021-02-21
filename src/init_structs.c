/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:17:56 by mifernan          #+#    #+#             */
/*   Updated: 2020/03/03 13:47:50 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_textures(t_datas *datas)
{
	int i;

	i = 0;
	while (i < 5)
	{
		datas->texts[i].str = NULL;
		datas->texts[i].sizel = 0;
		i++;
	}
}

void	ft_init_struct_datas(t_datas *datas)
{
	datas->res[0] = 0;
	datas->res[1] = 0;
	datas->floor[0] = 0;
	datas->floor[1] = 0;
	datas->floor[2] = 0;
	datas->sky[0] = 0;
	datas->sky[1] = 0;
	datas->sky[2] = 0;
	datas->h_map = 0;
	datas->l_map = NULL;
	datas->map = NULL;
	datas->obj_h = 0;
	datas->obj_col = 0;
	datas->obj_dist = 0;
	datas->obj_ori = 0;
	datas->nb_sprites = 0;
	datas->x = 0;
	ft_init_textures(datas);
}

void	ft_init_struct_player(t_player *player, t_datas *datas)
{
	player->x = 0;
	player->y = 0;
	player->dir = 0;
	player->height = datas->res[1] / 2;
	player->fov = 60;
	player->dist_proj = (datas->res[0] / 2)
	/ tan((M_PI / 180) * (player->fov / 2));
	player->angle_btwn = player->fov / datas->res[0];
	player->angle = 0;
	player->prec = 256;
	player->ax = 0;
	player->ay = 0;
	player->xa = 0;
	player->ya = 0;
	player->bx = 0;
	player->by = 0;
	player->xb = 0;
	player->yb = 0;
}

void	ft_init_node(t_node *node, t_datas *datas)
{
	int i;

	node->begin = NULL;
	node->end = NULL;
	i = 0;
	while (i <= datas->nb_sprites)
	{
		ft_sprite_add_back(node);
		i++;
	}
}
