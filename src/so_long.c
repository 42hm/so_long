/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 21:48:47 by hmoon             #+#    #+#             */
/*   Updated: 2022/05/24 18:32:02 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

static void	handle_event(t_mlx *mlx)
{
	t_mlx	*mlx_temp;

	mlx_temp = mlx;
	if (mlx_temp->map->maparr[mlx_temp->y][mlx_temp->x] == 'C')
	{
		mlx_temp->map->collect_num--;
		mlx_temp->map->maparr[mlx_temp->y][mlx_temp->x] = '0';
	}
	else if (mlx_temp->map->maparr[mlx_temp->y][mlx_temp->x] == 'E')
	{
		if (mlx_temp->map->collect_num == 0)
			so_long_exit(mlx_temp);
	}
	else if (mlx_temp->map->maparr[mlx_temp->y][mlx_temp->x] == 'B')
		so_long_exit(mlx_temp);
}

static int	get_key(int key, void *param)
{
	t_mlx	*mlx_temp;

	mlx_temp = (t_mlx *)param;
	if (key == ESC)
		so_long_exit(mlx_temp);
	else if (key == W || key == UP)
		move_up(mlx_temp);
	else if (key == A || key == LEFT)
		move_left(mlx_temp);
	else if (key == S || key == DOWN)
		move_down(mlx_temp);
	else if (key == D || key == RIGHT)
		move_right(mlx_temp);
	return (key);
}

static int	draw_loop(t_mlx *mlx)
{
	t_mlx	*mlx_temp;

	mlx_temp = mlx;
	if (mlx->loop == 40)
		mlx->loop = 0;
	mlx->loop++;
	mlx_clear_window(mlx->mlx_ptr, mlx->window);
	draw_map(mlx_temp);
	handle_event(mlx_temp);
	return (0);
}

static void	so_long(t_mlx *mlx)
{
	init_mlx(mlx);
	draw_map(mlx);
	mlx_hook(mlx->window, REDCROSS, 0, so_long_exit, mlx);
	mlx_key_hook(mlx->window, get_key, mlx);
	mlx_loop_hook(mlx->mlx_ptr, draw_loop, mlx);
	mlx_loop(mlx->mlx_ptr);
}

int	main(int ac, char **av)
{
	t_mlx	*mlx;

	is_file_compatibility(ac, av);
	mlx = alloc_mlx();
	is_map_compatibility(av[1], mlx->map);
	make_bonus(mlx->map);
	so_long(mlx);
}
