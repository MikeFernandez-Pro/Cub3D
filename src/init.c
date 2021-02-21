/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:17:12 by mifernan          #+#    #+#             */
/*   Updated: 2020/03/04 13:28:34 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_resolution(char *str, t_datas *datas)
{
	char **cpy;

	cpy = NULL;
	if (!str)
		return (-1);
	if (str[0] == 'R')
	{
		cpy = ft_split(str, ' ');
		if (ft_tablen(cpy) != 3)
			return (-1);
		datas->res[0] = ft_atoi(cpy[1]);
		datas->res[1] = ft_atoi(cpy[2]);
		ft_free_tab(cpy);
	}
	return (0);
}

int		ft_paths(char *str, t_datas *datas, t_window *window)
{
	int		nb;
	char	**tab;
	void	*ptr;
	int		x;

	if (!str)
		return (-1);
	tab = NULL;
	ptr = NULL;
	nb = ft_is_texture(str);
	x = 0;
	if (nb != -1)
	{
		tab = ft_split(str, ' ');
		if (!(ptr = mlx_xpm_file_to_image(window->mlx_ptr, tab[1], &x, &x)))
			return (-1);
		ft_free_tab(tab);
		datas->texts[nb].str = mlx_get_data_addr(ptr, &x,
		&datas->texts[nb].sizel, &x);
	}
	return (0);
}

void	ft_floornsky(char *str, t_datas *datas)
{
	char **cpy;

	if (!str)
		return ;
	if (str[0] == 'F')
	{
		cpy = ft_split(str, ',');
		if (ft_tablen(cpy) != 3 || ft_strlen(cpy[0]) < 2)
			return ;
		datas->floor[0] = ft_atoi(&cpy[0][1]);
		datas->floor[1] = ft_atoi(cpy[1]);
		datas->floor[2] = ft_atoi(cpy[2]);
		ft_free_tab(cpy);
	}
	else if (str[0] == 'C')
	{
		cpy = ft_split(str, ',');
		if (ft_tablen(cpy) != 3 || ft_strlen(cpy[0]) < 2)
			return ;
		datas->sky[0] = ft_atoi(&cpy[0][1]);
		datas->sky[1] = ft_atoi(cpy[1]);
		datas->sky[2] = ft_atoi(cpy[2]);
		ft_free_tab(cpy);
	}
}

void	ft_init_map(char *str, char **cpy_map, int start)
{
	if (!str)
		return ;
	if (str[start] == '1' || str[start] == '0')
	{
		*cpy_map = ft_strjoin_free(*cpy_map, str, 1);
		*cpy_map = ft_strjoin_free(*cpy_map, ",", 1);
	}
}

int		ft_find_datas(t_datas *datas, int argc, char **argv, t_window *window)
{
	char	*line;
	int		start;
	char	*cpy_map;
	int		fd;
	int		ret;

	ret = 1;
	if ((fd = open(argv[argc - 1], O_RDONLY)) == -1)
		return (-1);
	ft_init_lines(&line, &cpy_map);
	while (ret != 0)
	{
		ret = get_next_line(fd, &line);
		start = ft_del_space_start(line);
		if (ft_resolution(&line[start], datas) == -1
		|| ft_paths(&line[start], datas, window) == -1)
			return (-1);
		ft_floornsky(&line[start], datas);
		ft_init_map(line, &cpy_map, start);
		ft_strdel(&line);
	}
	datas->map = ft_split(cpy_map, ',');
	ft_strdel(&cpy_map);
	close(fd);
	return (0);
}
