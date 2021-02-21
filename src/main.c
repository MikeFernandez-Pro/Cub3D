/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 11:58:44 by mifernan          #+#    #+#             */
/*   Updated: 2020/03/04 15:02:41 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_movement(int key, t_structs *cub)
{
	int		j;

	j = 0;
	ft_forward(&cub->player, &cub->datas, key);
	ft_left(&cub->player, &cub->datas, key);
	ft_backward(&cub->player, &cub->datas, key);
	ft_right(&cub->player, &cub->datas, key);
	ft_attack(key, cub);
	ft_defend(key, cub);
	if (key == 65361)
		cub->player.dir += 10;
	if (key == 65363)
		cub->player.dir -= 10;
	cub->player.angle = cub->player.dir + 30;
	ft_draw_walls(cub);
	mlx_put_image_to_window(cub->window.mlx_ptr,
	cub->window.win_ptr, cub->window.img_ptr, 0, 0);
	mlx_put_image_to_window(cub->window.mlx_ptr, cub->window.win_ptr,
	mlx_xpm_file_to_image(cub->window.mlx_ptr,
	"xpmfiles/chill.xpm", &j, &j), 0, 0);
	mlx_loop_hook(cub->window.mlx_ptr, ft_animation, cub);
	return (0);
}

int		ft_close(t_structs *cub)
{
	mlx_destroy_window(cub->window.mlx_ptr, cub->window.win_ptr);
	exit(0);
	return (0);
}

int		ft_escape(int key, t_structs *cub)
{
	if (key == 65307)
	{
		mlx_destroy_window(cub->window.mlx_ptr, cub->window.win_ptr);
		exit(0);
	}
	return (0);
}

int		ft_init_world(char **argv, t_structs *cub)
{
	int		j;

	j = 0;
	cub->window.win_ptr = mlx_new_window(cub->window.mlx_ptr,
	cub->datas.res[0], cub->datas.res[1], "Cub3d");
	cub->window.img_ptr = mlx_new_image(cub->window.mlx_ptr,
	cub->datas.res[0], cub->datas.res[1]);
	cub->window.str = mlx_get_data_addr(cub->window.img_ptr,
	&j, &cub->window.sizel, &j);
	ft_draw_walls(cub);
	if (strncmp(argv[1], "--save", 6) == 0)
		export_bmp("screenshot.bmp", cub->window.str,
		cub->datas.res[0], cub->datas.res[1]);
	mlx_put_image_to_window(cub->window.mlx_ptr, cub->window.win_ptr,
	cub->window.img_ptr, 0, 0);
	mlx_put_image_to_window(cub->window.mlx_ptr, cub->window.win_ptr,
	mlx_xpm_file_to_image(cub->window.mlx_ptr,
	"xpmfiles/chill.xpm", &j, &j), 0, 0);
	mlx_hook(cub->window.win_ptr, 2, 1L << 0, ft_movement, cub);
	mlx_hook(cub->window.win_ptr, 17, 0, ft_close, cub);
	mlx_key_hook(cub->window.win_ptr, ft_escape, cub);
	mlx_loop(cub->window.mlx_ptr);
	return (0);
}

int		main(int argc, char **argv)
{
	t_structs cub;

	if ((argc < 2 || argc > 3) || (argc == 2 && ft_strlen(argv[1]) > 3
	&& ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 4) != 0)
	|| (argc == 3 && ft_strlen(argv[2]) > 3
	&& (ft_strncmp(&argv[2][ft_strlen(argv[2]) - 4], ".cub", 4) != 0
	|| ft_strncmp(argv[1], "--save", 6) != 0)))
	{
		ft_putstr_fd("Error\n", 0);
		return (-1);
	}
	ft_init_struct_datas(&cub.datas);
	cub.window.mlx_ptr = mlx_init();
	if (ft_find_datas(&cub.datas, argc, argv, &cub.window) == -1
	|| ft_verification_map(&cub.datas) == -1)
	{
		ft_putstr_fd("Error\n", 0);
		return (-1);
	}
	ft_init_struct_player(&cub.player, &cub.datas);
	ft_init_node(&cub.node, &cub.datas);
	ft_player_pos(&cub.player, cub.datas.map);
	ft_init_world(argv, &cub);
	return (0);
}
