/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:04:54 by mifernan          #+#    #+#             */
/*   Updated: 2020/03/02 15:28:50 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_texts(t_structs *cub)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (cub->datas.texts[i].str)
			mlx_destroy_image(cub->window.mlx_ptr, cub->datas.texts[i].str);
		i++;
	}
}

void	ft_free_sprites(t_node *node)
{
	t_sprites *current;

	if (node->end)
	{
		current = node->end->prev;
		while (current->prev)
		{
			free(node->end);
			node->end = current;
			current = current->prev;
		}
		free(node->end);
		free(current);
	}
}
