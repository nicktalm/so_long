/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:41:56 by ntalmon           #+#    #+#             */
/*   Updated: 2023/12/14 13:05:26 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	create_img(t_vars *data)
{
	data->textures[P] = mlx_load_png("textures/duck.png");
	data->textures[C] = mlx_load_png("textures/bread.png");
	data->textures[W] = mlx_load_png("textures/wall.png");
	data->textures[S] = mlx_load_png("textures/ground.png");
	data->textures[E] = mlx_load_png("textures/exit.png");
	data->image[P] = mlx_texture_to_image(data->mlx, data->textures[P]);
	data->image[C] = mlx_texture_to_image(data->mlx, data->textures[C]);
	data->image[W] = mlx_texture_to_image(data->mlx, data->textures[W]);
	data->image[S] = mlx_texture_to_image(data->mlx, data->textures[S]);
	data->image[E] = mlx_texture_to_image(data->mlx, data->textures[E]);
}

void	create_w_s(t_vars *data)
{
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (data->map[j] != NULL)
	{
		i = 0;
		while (data->map[j][i] != '\n' && data->map[j][i])
		{
			if (data->map[j][i] == '1')
				mlx_image_to_window(data->mlx, data->image[W], i * 32, j * 32);
			if (data->map[j][i] == '0')
				mlx_image_to_window(data->mlx, data->image[S], i * 32, j * 32);
			i++;
		}
		j++;
	}
}

void	create_c_e(t_vars *data)
{
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (data->map[j] != NULL)
	{
		i = 0;
		while (data->map[j][i] != '\n' && data->map[j][i])
		{
			if (data->map[j][i] == 'C')
			{
				mlx_image_to_window(data->mlx, data->image[S], i * 32, j * 32);
				mlx_image_to_window(data->mlx, data->image[C], i * 32, j * 32);
			}
			if (data->map[j][i] == 'E')
			{
				mlx_image_to_window(data->mlx, data->image[S], i * 32, j * 32);
				mlx_image_to_window(data->mlx, data->image[E], i * 32, j * 32);
			}
			i++;
		}
		j++;
	}
}

void	create_p(t_vars *data)
{
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (data->map[j] != NULL)
	{
		i = 0;
		while (data->map[j][i] != '\n' && data->map[j][i])
		{
			if (data->map[j][i] == 'P')
			{
				data->p_w = i;
				data->p_h = j;
				mlx_image_to_window(data->mlx, data->image[S],
					data->p_w * 32, data->p_h * 32);
				mlx_image_to_window(data->mlx, data->image[P],
					data->p_w * 32, data->p_h * 32);
			}
			i++;
		}
		j++;
	}
}
