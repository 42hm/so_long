/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:33:30 by hmoon             #+#    #+#             */
/*   Updated: 2022/05/24 17:14:17 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_up(t_mlx *mlx)
{
	mlx->cur_key = 'W';
	mlx->map->maparr[map->y][map->x] = '0';
	mlx->y -= 1;
	if (mlx->map->maparr[map->y][map->x] == '1')
		map->y += 1;
	mlx->map->maparr[map->y][map->x] = 'P';
	mlx->move_count++;
	ft_putstr_fd("Move : ", 1);
	ft_putnbr_fd(mlx->move_count, 1);
	ft_putchar_fd('\n', 1);
}

void	move_left(t_mlx *mlx)
{
	mlx->cur_key = 'A';
	mlx->map->maparr[map->y][map->x] = '0';
	mlx->x -= 1;
	if (mlx->map->maparr[map->y][map->x] == '1')
		map->x += 1;
	mlx->map->maparr[map->y][map->x] = 'P';
	mlx->move_count++;
	ft_putstr_fd("Move : ", 1);
	ft_putnbr_fd(mlx->move_count, 1);
	ft_putchar_fd('\n', 1);
}

void	move_down(t_mlx *mlx)
{
	mlx->cur_key = 'S';
	mlx->map->maparr[map->y][map->x] = '0';
	mlx->y += 1;
	if (mlx->map->maparr[map->y][map->x] == '1')
		map->y -= 1;
	mlx->map->maparr[map->y][map->x] = 'P';
	mlx->move_count++;
	ft_putstr_fd("Move : ", 1);
	ft_putnbr_fd(mlx->move_count, 1);
	ft_putchar_fd('\n', 1);
}

void	move_right(t_mlx *mlx)
{
	mlx->cur_key = 'D';
	mlx->map->maparr[map->y][map->x] = '0';
	mlx->x += 1;
	if (mlx->map->maparr[map->y][map->x] == '1')
		map->x -= 1;
	mlx->map->maparr[map->y][map->x] = 'P';
	mlx->move_count++;
	ft_putstr_fd("Move : ", 1);
	ft_putnbr_fd(mlx->move_count, 1);
	ft_putchar_fd('\n', 1);
}
