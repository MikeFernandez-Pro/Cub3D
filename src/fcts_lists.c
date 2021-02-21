/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcts_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 10:31:55 by mifernan          #+#    #+#             */
/*   Updated: 2020/03/02 15:28:20 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprites	*ft_new_sprite(void)
{
	t_sprites *sprites;

	if (!(sprites = (t_sprites*)malloc(sizeof(t_sprites))))
		return (NULL);
	sprites->cx = -1;
	sprites->cy = -1;
	sprites->dx = -1;
	sprites->dy = -1;
	sprites->height = 0;
	sprites->col = 0;
	sprites->prev = NULL;
	sprites->next = NULL;
	return (sprites);
}

void		ft_reset_sprites(t_node *node)
{
	t_sprites *current;

	current = node->begin;
	while (current)
	{
		current->cx = -1;
		current->cy = -1;
		current->dx = -1;
		current->dy = -1;
		current->height = 0;
		current->col = 0;
		current = current->next;
	}
}

void		ft_sprite_add_back(t_node *node)
{
	t_sprites *new;

	if (!(new = ft_new_sprite()))
		return ;
	if (!node->begin)
	{
		node->begin = new;
		node->end = new;
		new->prev = NULL;
		new->next = NULL;
	}
	else
	{
		new->prev = node->end;
		new->prev->next = new;
		new->next = NULL;
		node->end = new;
	}
}

void		ft_hor_value(t_sprites *sprite, t_player *player)
{
	sprite->cx = player->ax;
	sprite->cy = player->ay;
}

void		ft_ver_value(t_sprites *sprite, t_player *player)
{
	sprite->dx = player->bx;
	sprite->dy = player->by;
}
