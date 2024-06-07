/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:47:38 by ntalmon           #+#    #+#             */
/*   Updated: 2023/12/14 13:05:37 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_point	map_size;
	t_vars	data;

	data.steps = 0;
	data.map = start(argc, argv);
	map_size = count_size_map(data.map);
	data.mlx = mlx_init(map_size.x * 32, map_size.y * 32, "so_long", true);
	create_img(&data);
	create_w_s(&data);
	create_c_e(&data);
	create_p(&data);
	mlx_set_window_limit(data.mlx, map_size.x * 32, map_size.y * 32,
		map_size.x * 32, map_size.y * 32);
	data.player_img = data.image[P];
	mlx_key_hook(data.mlx, key_overview, &data);
	mlx_loop(data.mlx);
	return (0);
}
