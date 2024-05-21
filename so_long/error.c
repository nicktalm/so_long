/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:22:05 by ntalmon           #+#    #+#             */
/*   Updated: 2023/12/12 17:00:07 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	error_characters(int *e, int *c, int *p, char **map)
{
	if (*e != 1)
		ft_printf("Error:\nThe map must contain exactly 1 exit E!\n");
	if (*c <= 0)
		ft_printf("Error:\nThe map must contain at least 1 collectible C!\n");
	if (*p != 1)
		ft_printf("Error:\nThe map must contain 1 starting position P!\n");
	free_map(map);
	exit (0);
	return (0);
}

void	error(int i, char **map)
{
	if (i == 1)
		ft_printf("Error:\nThe map must be rectangular!\n");
	if (i == 2)
		ft_printf("Error:\nThe map must be closed/surrounded by walls!\n");
	if (i == 3)
		ft_printf("Error:\nNo Valid Path!\n");
	if (i == 6)
		ft_printf("Error:\nNon-valid character inside the map!\n");
	if (i == 7)
		ft_printf("Error:\nNot enough lines or empty file!\n");
	if (i == 8)
		ft_printf("Error:\nAllocation fails in dupmap!\n");
	free_map(map);
	exit (0);
}

void	error2(int i)
{
	if (i == 4)
		ft_printf("Error:\nWrong file type, it must be a .ber file!\n");
	if (i == 5)
		ft_printf("Error:\nExactly 1 argument is required!\n");
	exit (0);
}

// ft_printf(GREEN"\n\
// ██████████████████████████████████████████████████████████████████\n\
// ██                                                              ██\n\
// ██  ███  ███  ██████  ██    ██     ██      ██ ██ ██    ██   ██  ██\n\
// ██   ██  ██  ██    ██ ██    ██     ██      ██ ██ ███   ██   ██  ██\n\
// ██    ████   █      █ ██    ██     ██  ██  ██ ██ ██ ██ ██   ██  ██\n\
// ██     ██    ██    ██ ██    ██     ██ ████ ██ ██ ██  ████       ██\n\
// ██     ██     ██████    ████        ███  ███  ██ ██   ███   ██  ██\n\
// ██                                                              ██\n\
// ██████████████████████████████████████████████████████████████████\n\
// 		");