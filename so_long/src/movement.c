/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:11:23 by ntalmon           #+#    #+#             */
/*   Updated: 2023/12/14 13:05:34 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	playerup(t_vars *vars)
{
	int	w;
	int	h;

	w = vars->p_w;
	h = vars->p_h;
	if (vars->map[h - 1][w] != '1')
	{
		vars->player_img->instances[0].y -= 32;
		vars->p_w = w;
		vars->p_h = h - 1;
		exit_and_collectible(vars);
	}
}

void	playerdown(t_vars *vars)
{
	int	w;
	int	h;

	w = vars->p_w;
	h = vars->p_h;
	if (vars->map[h + 1][w] != '1')
	{
		vars->player_img->instances[0].y += 32;
		vars->p_w = w;
		vars->p_h = h + 1;
		exit_and_collectible(vars);
	}
}

void	playerright(t_vars *vars)
{
	int	w;
	int	h;

	w = vars->p_w;
	h = vars->p_h;
	if (vars->map[h][w + 1] != '1')
	{
		vars->player_img->instances[0].x += 32;
		vars->p_w = w + 1;
		vars->p_h = h;
		exit_and_collectible(vars);
	}
}

void	playerleft(t_vars *vars)
{
	int	w;
	int	h;

	w = vars->p_w;
	h = vars->p_h;
	if (vars->map[h][w - 1] != '1')
	{
		vars->player_img->instances[0].x -= 32;
		vars->p_w = w - 1;
		vars->p_h = h;
		exit_and_collectible(vars);
	}
}

void	key_overview(mlx_key_data_t keydata, void	*param)
{
	t_vars	*data;

	data = param;
	count_c(data);
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(data->mlx);
		exit_and_free(data);
	}
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		playerup(data);
	if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		playerdown(data);
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		playerleft(data);
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		playerright(data);
}
