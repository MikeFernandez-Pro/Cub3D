/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:05:07 by mifernan          #+#    #+#             */
/*   Updated: 2020/03/03 13:06:52 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_skynfloor(t_window *window, t_datas *datas)
{
	int i;
	int j;

	i = 0;
	while (i < datas->res[0])
	{
		j = 0;
		while (j < datas->res[1])
		{
			if (j < datas->res[1] / 2)
				ft_put_pixel(i, j, 65536 * datas->sky[0]
				+ 256 * datas->sky[1] + datas->sky[2], window);
			else
				ft_put_pixel(i, j, 65536 * datas->floor[0]
				+ 256 * datas->floor[1] + datas->floor[2], window);
			j++;
		}
		i++;
	}
}

void	ft_sprites_pixels(t_structs *cub, int x, t_sprites *current)
{
	int y;
	int yim;
	int color;

	y = (cub->datas.res[1] / 2) - (current->height / 2);
	yim = 0;
	while (y < cub->datas.res[1] / 2 + current->height / 2 &&
	y < cub->datas.res[1] - 1)
	{
		if (y >= 0 && y < cub->datas.res[1]
		&& current->height > cub->datas.obj_h)
		{
			color = get_color_sprite(yim, &cub->datas,
			&cub->player, current);
			if (color != 0)
				ft_put_pixel(x, y, color, &cub->window);
		}
		y++;
		yim++;
	}
}

void	ft_draw_sprites(t_structs *cub, int x)
{
	t_sprites	*current;

	current = cub->node.end;
	while (current)
	{
		ft_sprites_pixels(cub, x, current);
		current = current->prev;
	}
}

void	ft_walls_pixels(t_structs *cub, int x)
{
	int y;
	int yim;
	int color;

	y = (cub->datas.res[1] / 2) - (cub->datas.obj_h / 2);
	cub->player.angle -= cub->player.angle_btwn;
	yim = 0;
	while (y < cub->datas.res[1] / 2 + cub->datas.obj_h / 2 &&
	y < cub->datas.res[1] - 1)
	{
		if (y >= 0 && y < cub->datas.res[1])
		{
			color = get_color_texture(yim, &cub->datas, &cub->player);
			if (color != 0)
				ft_put_pixel(x, y, color, &cub->window);
		}
		y++;
		yim++;
	}
}

void	ft_draw_walls(t_structs *cub)
{
	int		x;

	ft_draw_skynfloor(&cub->window, &cub->datas);
	x = -1;
	while (++x < cub->datas.res[0])
	{
		ft_distance_wall(&cub->player, &cub->datas, &cub->node);
		ft_distance_sprites(&cub->player, &cub->node);
		ft_walls_pixels(cub, x);
		ft_draw_sprites(cub, x);
		ft_reset_sprites(&cub->node);
	}
}
