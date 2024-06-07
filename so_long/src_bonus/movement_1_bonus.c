/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_1_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:11:23 by ntalmon           #+#    #+#             */
/*   Updated: 2023/12/14 12:40:33 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	playerup(t_vars *data)
{
	int	w;
	int	h;

	w = data->p_w;
	h = data->p_h;
	if (data->map[h - 1][w] != '1')
	{
		data->player_img->instances[0].y -= 32;
		data->p_w = w;
		data->p_h = h - 1;
		exit_and_collectible(data);
	}
}

void	playerdown(t_vars *data)
{
	int	w;
	int	h;

	w = data->p_w;
	h = data->p_h;
	if (data->map[h + 1][w] != '1')
	{
		data->player_img->instances[0].y += 32;
		data->p_w = w;
		data->p_h = h + 1;
		exit_and_collectible(data);
	}
}

void	playerright(t_vars *data)
{
	int	w;
	int	h;

	w = data->p_w;
	h = data->p_h;
	if (data->map[h][w + 1] != '1')
	{
		data->player_img->instances[0].x += 32;
		data->p_w = w + 1;
		data->p_h = h;
		exit_and_collectible(data);
	}
}

void	playerleft(t_vars *data)
{
	int	w;
	int	h;

	w = data->p_w;
	h = data->p_h;
	if (data->map[h][w - 1] != '1')
	{
		data->player_img->instances[0].x -= 32;
		data->p_w = w - 1;
		data->p_h = h;
		exit_and_collectible(data);
	}
}

void	key_overview(mlx_key_data_t keydata, void	*param)
{
	t_vars	*data;
	int		w;
	int		h;

	data = param;
	w = data->p_w;
	h = data->p_h;
	count_c(data);
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(data->mlx);
		exit_and_free(data);
	}
	if (data->map[h][w] != 'X' && data->map[h][w] != '1')
	{
		movement(keydata, data);
	}
}
