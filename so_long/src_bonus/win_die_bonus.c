/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_die_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:05:13 by ntalmon           #+#    #+#             */
/*   Updated: 2023/12/14 11:35:30 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	you_win(t_vars *data)
{
	int		j;
	int		i;

	i = 0;
	j = 0;
	ft_printf("\nCongrats, you won with %i moves!\n\n", data->steps);
	while (data->map[j] != NULL)
	{
		i = 0;
		while (data->map[j][i] != '\n' && data->map[j][i])
		{
			if (data->map[j][i])
			{
				data->p_w = i;
				data->p_h = j;
				mlx_image_to_window(data->mlx, data->image[S],
					data->p_w * 32, data->p_h * 32);
			}
			i++;
		}
		j++;
	}
	message_win(data);
}

void	message_win(t_vars *data)
{
	int	col;
	int	row;

	col = (count_column(data) - 1) / 2;
	row = (get_string_length(data->map[1]) - 1) / 2;
	mlx_put_string(data->mlx, "You won!", (row * 32) - 25, (col * 32) - 20);
	mlx_put_string(data->mlx, "Press ESC!", (row * 32) - 35, (col * 32 + 20));
}

void	you_died(t_vars *data)
{
	int		j;
	int		i;

	i = 0;
	j = 0;
	data->steps++;
	ft_printf("\nYou died!\n\n");
	while (data->map[j] != NULL)
	{
		i = 0;
		while (data->map[j][i] != '\n' && data->map[j][i])
		{
			if (data->map[j][i])
			{
				data->p_w = i;
				data->p_h = j;
				mlx_image_to_window(data->mlx, data->image[S],
					data->p_w * 32, data->p_h * 32);
			}
			i++;
		}
		j++;
	}
	message_died(data);
}

void	message_died(t_vars *data)
{
	int	col;
	int	row;

	col = (count_column(data) - 1) / 2;
	row = (get_string_length(data->map[1]) - 1) / 2;
	mlx_put_string(data->mlx, "You died!", (row * 32) - 25, (col * 32) - 20);
	mlx_put_string(data->mlx, "Press ESC!", (row * 32) - 30, (col * 32 + 20));
}
