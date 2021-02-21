/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 13:10:57 by mifernan          #+#    #+#             */
/*   Updated: 2020/04/10 00:27:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	**ft_init_anim(t_structs *cub)
{
	void	**anim;
	int		j;

	if (!(anim = malloc(sizeof(void*) * 5)))
		return (NULL);
	j = 0;
	anim[0] = mlx_xpm_file_to_image(cub->window.mlx_ptr,
	"xpmfiles/fire1.xpm", &j, &j);
	anim[1] = mlx_xpm_file_to_image(cub->window.mlx_ptr,
	"xpmfiles/fire2.xpm", &j, &j);
	anim[2] = mlx_xpm_file_to_image(cub->window.mlx_ptr,
	"xpmfiles/fire3.xpm", &j, &j);
	anim[3] = mlx_xpm_file_to_image(cub->window.mlx_ptr,
	"xpmfiles/fire4.xpm", &j, &j);
	anim[4] = mlx_xpm_file_to_image(cub->window.mlx_ptr,
	"xpmfiles/fire5.xpm", &j, &j);
	return (anim);
}

void	ft_timer(t_structs *cub)
{
	int j;

	j = -1;
	while (++j < 5)
		mlx_do_sync(cub->window.mlx_ptr);
}

int		ft_animation(t_structs *cub)
{
	int		i;
	int		j;
	void	**anim;

	anim = NULL;
	i = -1;
	if (cub->datas.map[(int)(cub->player.y / cub->player.prec)]
	[(int)(cub->player.x / cub->player.prec)] == '2')
	{
		anim = ft_init_anim(cub);
		while (++i < 5)
		{
			mlx_put_image_to_window(cub->window.mlx_ptr,
			cub->window.win_ptr, anim[i], 0, 0);
			ft_timer(cub);
			mlx_destroy_image(cub->window.mlx_ptr, anim[i]);
		}
		free(anim);
		mlx_put_image_to_window(cub->window.mlx_ptr, cub->window.win_ptr,
		cub->window.img_ptr, 0, 0);
		mlx_put_image_to_window(cub->window.mlx_ptr, cub->window.win_ptr,
		mlx_xpm_file_to_image(cub->window.mlx_ptr,
		"xpmfiles/chill.xpm", &j, &j), 0, 0);
	}
	return (0);
}

void	ft_attack(int key, t_structs *cub)
{
	void	*attack;
	int		j;

	attack = NULL;
	j = 0;
	if (key == 101)
	{
		mlx_put_image_to_window(cub->window.mlx_ptr, cub->window.win_ptr,
		cub->window.img_ptr, 0, 0);
		attack = mlx_xpm_file_to_image(cub->window.mlx_ptr,
		"xpmfiles/attack.xpm", &j, &j);
		mlx_put_image_to_window(cub->window.mlx_ptr,
		cub->window.win_ptr, attack, 0, 0);
		mlx_do_sync(cub->window.mlx_ptr);
		mlx_destroy_image(cub->window.mlx_ptr, attack);
		mlx_put_image_to_window(cub->window.mlx_ptr,
		cub->window.win_ptr, cub->window.img_ptr, 0, 0);
		mlx_put_image_to_window(cub->window.mlx_ptr, cub->window.win_ptr,
		mlx_xpm_file_to_image(cub->window.mlx_ptr,
		"xpmfiles/chill.xpm", &j, &j), 0, 0);
	}
}

void	ft_defend(int key, t_structs *cub)
{
	void	*defend;
	int		j;

	defend = NULL;
	j = 0;
	if (key == 97)
	{
		mlx_put_image_to_window(cub->window.mlx_ptr,
		cub->window.win_ptr, cub->window.img_ptr, 0, 0);
		defend = mlx_xpm_file_to_image(cub->window.mlx_ptr,
		"xpmfiles/defend.xpm", &j, &j);
		mlx_put_image_to_window(cub->window.mlx_ptr,
		cub->window.win_ptr, defend, 0, 0);
		mlx_do_sync(cub->window.mlx_ptr);
		mlx_destroy_image(cub->window.mlx_ptr, defend);
		mlx_put_image_to_window(cub->window.mlx_ptr,
		cub->window.win_ptr, cub->window.img_ptr, 0, 0);
		mlx_put_image_to_window(cub->window.mlx_ptr, cub->window.win_ptr,
		mlx_xpm_file_to_image(cub->window.mlx_ptr,
		"xpmfiles/chill.xpm", &j, &j), 0, 0);
	}
}
