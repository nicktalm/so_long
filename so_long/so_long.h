/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:25:28 by ntalmon           #+#    #+#             */
/*   Updated: 2023/12/12 18:00:29 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "lib/get_next_line/get_next_line.h"
# include "lib/libft/libft.h"
# include "lib/printf/ft_printf.h"
# include "lib/libmlx/include/MLX42/MLX42.h"

# define TEXTURES			5
# define S					0
# define P					1
# define W					2
# define C					3
# define E					4

# define GREEN				"\033[0;32m"

typedef struct s_vars
{
	mlx_t			*mlx;

	mlx_texture_t	*textures[TEXTURES];

	mlx_image_t		*image[TEXTURES];

	mlx_image_t		*map_img;
	mlx_image_t		*player_img;
	int				p_w;
	int				p_h;
	int				steps;

	int				coll_nbr;
	int				player_no;
	int				exit_no;
	char			**map;
}				t_vars;

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

char		**start(int argc, char **argv);
t_point		count_size_map(char **map);

int			get_string_length(const char *str);
int			check_all_row_lengths(char **map, int first_row_length);
int			check_map_rectangular(char **map);

int			check_map_characters(char **map);
t_point		count_characters(char **map, int *e, int *c, int *p);

int			check_map_surrounded(char **map);

int			check_map_valid_char(char **map);

int			error_characters(int *e, int *c, int *p, char **map);
void		error(int i, char **map);
void		exit_and_free(t_vars *vars);
void		exit_and_collectible(t_vars *vars);

int			check_map_path(char **map, t_point	size);
void		fill(char **map, t_point size, t_point position_p);

int			check_map(char **map);

t_point		search_p(char **map);
char		**dupmap(char **map, t_point	size);

char		**create_map(char **argv);
int			count_rows(int fd);
int			count_rows_2(char *buffer, int counter, int i);

void		playerup(t_vars *vars);
void		playerdown(t_vars *vars);
void		playerleft(t_vars *vars);
void		playerright(t_vars *vars);
void		key_overview(mlx_key_data_t keydata, void	*param);

void		check_z_instances(t_vars *vars);
int			count_c(t_vars	*vars);

void		create_img(t_vars *data);
void		create_w_s(t_vars *data);
void		create_c_e(t_vars *data);
void		create_p(t_vars *data);

void		freearray(char **cpymap);
void		freearray2(char **cpymap);

void		leaks(void);

void		free_map(char **map);
void		error2(int i);

void		display_in_window(t_vars *data);

int			count_column(t_vars *data);
void		display_in_window(t_vars *data);

#endif