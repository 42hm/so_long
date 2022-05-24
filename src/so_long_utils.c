/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:02:27 by hmoon             #+#    #+#             */
/*   Updated: 2022/05/24 17:26:50 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static	void	destroy_image(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->map->wall);
	mlx_destroy_image(mlx->mlx_ptr, mlx->map->floor);
	mlx_destroy_image(mlx->mlx_ptr, mlx->map->enemy);
	mlx_destroy_image(mlx->mlx_ptr, mlx->map->collect);
	mlx_destroy_image(mlx->mlx_ptr, mlx->map->player);
}

void	so_long_exit(t_mlx *mlx)
{
	int	i;

	i = 0;
	destroy_image(mlx);
	mlx_destroy_window(mlx->mlx_ptr, mlx->window);
	while (mlx->map->maparr[i] != 0)
	{
		free(mlx->map->maparr[i]);
		i++;
	}
	free(mlx->map->maparr);
	free(mlx->map);
	free(mlx);
	exit(0);
}

void	make_bonus(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height && i < map->width)
	{
		if (map->maparr[i][i + map->width / 3] == '0')
			map->maparr[i][i + map->width / 3] = 'B';
		i += 2;
	}
}

t_mlx	*alloc_mlx(void)
{
	t_mlx	*temp;

	temp = ft_malloc(sizeof(t_mlx));
	ft_memset(temp, 0, sizeof(t_mlx));
	temp->map = ft_malloc(sizeof(t_map));
	ft_memset(temp->map, 0, sizeof(t_map));
	return (temp);
}
