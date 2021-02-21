/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 11:52:43 by mifernan          #+#    #+#             */
/*   Updated: 2020/04/15 15:04:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <math.h>
# include "../minilibx/mlx.h"
# include <stdio.h>
# include <unistd.h>

typedef struct			s_texts
{
	char				*str;
	int					sizel;
}						t_texts;

typedef struct			s_sprites
{
	double				cx;
	double				cy;
	double				dx;
	double				dy;
	int					height;
	int					col;
	struct s_sprites	*prev;
	struct s_sprites	*next;
}						t_sprites;

typedef	struct			s_node
{
	int					len;
	t_sprites			*begin;
	t_sprites			*end;
}						t_node;

typedef struct			s_datas
{
	int					res[2];
	int					floor[3];
	int					sky[3];
	int					h_map;
	int					*l_map;
	char				**map;
	int					obj_h;
	int					obj_col;
	double				obj_dist;
	int					obj_ori;
	int					nb_sprites;
	int					x;
	t_texts				texts[5];

}						t_datas;

typedef struct			s_player
{
	double				x;
	double				y;
	double				dir;
	double				height;
	double				fov;
	double				dist_proj;
	double				angle_btwn;
	double				angle;
	double				prec;
	double				ax;
	double				ay;
	double				xa;
	double				ya;
	double				bx;
	double				by;
	double				xb;
	double				yb;
}						t_player;

typedef struct			s_window
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	char				*str;
	int					sizel;
}						t_window;

typedef struct			s_structs
{
	t_datas				datas;
	t_player			player;
	t_window			window;
	t_node				node;
}						t_structs;

int						ft_resolution(char *str, t_datas *datas);
int						ft_paths(char *str, t_datas *datas, t_window *window);
void					ft_floornsky(char *str, t_datas *datas);
void					ft_init_map(char *str, char **cpy_map, int start);
int						ft_find_datas(t_datas *datas, int argc,
						char **argv, t_window *window);
int						ft_tablen(char **str);
int						ft_verif_spaces(t_datas *datas);
int						ft_verif_player_pos(t_datas *datas);
int						ft_is_texture(char *str);
void					ft_init_lines(char **line, char **cpy_map);
void					ft_init_struct_datas(t_datas *datas);
void					ft_init_struct_player(t_player *player, t_datas *datas);
t_sprites				*ft_new_sprite(void);
void					ft_init_node(t_node *node, t_datas *datas);
void					ft_init_sprites(t_node *node, t_datas *datas);
t_sprites				*ft_last_sprite(t_sprites *lst);
void					ft_sprite_add_back(t_node *node);
void					ft_hor_value(t_sprites *sprites, t_player *player);
void					ft_ver_value(t_sprites *sprites, t_player *player);
void					ft_reset_sprites(t_node *node);
int						ft_verification_map(t_datas *datas);
int						ft_fstlst(t_datas *datas);
int						ft_find_sprites(char **map);
int						ft_global_verif(t_datas *datas);
char					*ft_strdup_free(char *s1);
char					*ft_del_spc(char *str);
int						ft_del_space_start(char *str);
int						ft_ispos(char c);
double					ft_direction(char c);
void					ft_player_pos(t_player *player, char **map);
void					ft_horizontal_check(t_player *player,
						t_datas *datas, t_node *node);
void					ft_horizontal_obst(t_datas *datas,
						t_player *player, t_node *node);
void					ft_vertical_check(t_player *player,
						t_datas *datas, t_node *node);
void					ft_vertical_obst(t_datas *datas,
						t_player *player, t_node *node);
void					ft_orientation(t_datas *datas, t_player *player);
void					ft_distance_wall(t_player *player,
						t_datas *datas, t_node *node);
void					ft_distance_sprites(t_player *player, t_node *node);
void					ft_put_pixel(int x, int y, int color, t_window *window);
int						get_color_sprite(int y, t_datas *datas,
						t_player *player, t_sprites *sprites);
int						get_color_texture(int y, t_datas *datas,
						t_player *player);
void					ft_draw_skynfloor(t_window *window, t_datas *datas);
void					ft_draw_walls(t_structs *cub);
int						ft_is_obstacle(t_player *player,
						t_datas *datas, int key);
void					ft_forward(t_player *player, t_datas *datas, int key);
void					ft_left(t_player *player, t_datas *datas, int key);
void					ft_backward(t_player *player, t_datas *datas, int key);
void					ft_right(t_player *player, t_datas *datas, int key);
void					**ft_init_anim(t_structs *cub);
void					ft_timer(t_structs *cub);
int						ft_animation(t_structs *cub);
void					ft_attack(int key, t_structs *cub);
void					ft_defend(int key, t_structs *cub);
void					ft_bmp_file(t_structs *cub);
void					export_bmp(char *name, char *addr,
						int width, int height);

#endif
