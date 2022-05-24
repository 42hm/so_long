/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 21:48:47 by hmoon             #+#    #+#             */
/*   Updated: 2022/05/24 22:12:33 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
