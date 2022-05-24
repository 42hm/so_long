/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:34:23 by hmoon             #+#    #+#             */
/*   Updated: 2022/05/24 09:46:36 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	set_player_first(t_mlx *mlx, int temp)
{
	if (mlx->cur_key == 'S' || mlx)
		mlx->map->player = mlx_xpm_file_to_image(mlx->mlx_ptr, \
		"./img/players.xpm", &temp, &temp);
	if (mlx->cur_key == 'S')
		mlx->map->player = mlx_xpm_file_to_image(mlx->mlx_ptr, \
		"./img/players.xpm", &temp, &temp);
	if (mlx->cur_key == 'S')
		mlx->map->player = mlx_xpm_file_to_image(mlx->mlx_ptr, \
		"./img/players.xpm", &temp, &temp);
	if (mlx->cur_key == 'S')
		mlx->map->player = mlx_xpm_file_to_image(mlx->mlx_ptr, \
		"./img/players.xpm", &temp, &temp);
}

int		init_images(t_mlx *mlx)
{
	int	temp;

	temp = BITSIZE;
	mlx->map->floor = mlx_xpm_file_to_image(mlx->mlx_ptr, "./img/floor.xpm", \
	&temp, &temp);
	if (20 < mlx->loop)
	{
		set_player_first(mlx, temp);
		set_images_first(mlx, temp);
	}
	else
	{
		set_player_second(mlx, temp);
		set_images_second(mlx, temp);
	}
}
