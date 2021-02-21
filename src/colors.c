/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 13:06:30 by mifernan          #+#    #+#             */
/*   Updated: 2020/03/03 13:06:59 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_pixel(int x, int y, int color, t_window *window)
{
	int	i;

	i = x * 4 + window->sizel * y;
	window->str[i] = color & 0xff;
	window->str[++i] = (color >> 8) & 0xff;
	window->str[++i] = (color >> 16) & 0xff;
}

int		get_color_texture(int y, t_datas *datas, t_player *player)
{
	int color;

	y = (double)y / (double)datas->obj_h * player->prec;
	color = datas->texts[datas->obj_ori].str[(datas->obj_col * 4)
	+ (datas->texts[datas->obj_ori].sizel * y)];
	color += datas->texts[datas->obj_ori].str[(datas->obj_col * 4)
	+ (datas->texts[datas->obj_ori].sizel * y)
		+ 1] * 256;
	color += (datas->texts[datas->obj_ori].str[(datas->obj_col * 4)
	+ (datas->texts[datas->obj_ori].sizel * y)
		+ 2] * 256) * 256;
	return (color);
}

int		get_color_sprite(int y, t_datas *datas,
t_player *player, t_sprites *sprites)
{
	int color;

	y = (double)y / (double)sprites->height * player->prec;
	color = datas->texts[4].str[(sprites->col * 4)
	+ (datas->texts[4].sizel * y)];
	color += datas->texts[4].str[(sprites->col * 4)
	+ (datas->texts[4].sizel * y)
		+ 1] * 256;
	color += (datas->texts[4].str[(sprites->col * 4)
	+ (datas->texts[4].sizel * y)
		+ 2] * 256) * 256;
	return (color);
}
