/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 08:40:56 by hmoon             #+#    #+#             */
/*   Updated: 2022/05/24 09:35:46 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_map(t_mlx *mlx)
{
	int	x;
	int	y;

	init_images(mlx);
}

void	init_mlx(t_mlx *mlx)
{
	int	x;
	int	y;

	mlx->mlx_ptr = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx_ptr, mlx->map->width * BITSIZE, \
			mlx->map->height * BITSIZE, "so_long");
	if (mlx->window == NULL)
		ft_error_exit("Error\nmlx_new_window error");
	y = -1;
	while (++y < mlx->map->height)
	{
		x = -1;
		while (++x < mlx->map->width)
		{
			if (mlx->map->maparr[y][x] == 'P')
			{
				mlx->x = x;
				mlx->y = y;
				mlx->cur_key = 'S';
				mlx->map->collect_num = -1;
				mlx->loop = 0;
				mlx->move_count = 0;
				return ;
			}
		}
	}
}
