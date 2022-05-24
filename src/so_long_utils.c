/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:02:27 by hmoon             #+#    #+#             */
/*   Updated: 2022/05/24 22:35:36 by hmoon            ###   ########.fr       */
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

int	so_long_exit(t_mlx *mlx)
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
	return (0);
}

void	make_bonus(t_map *map)
{
	int	mod;
	int	n;
	int	i;

	i = 1;
	n = 9;
	while (map->maparr[i] != 0)
	{
		mod = ((map->width % n) * i - i);
		if (mod >= map->width)
		{
			mod = ((map->width % i) * (n % i));
		}
		if (map->maparr[i][mod] == '0')
			map->maparr[i][mod] = 'B';
		i++;
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
