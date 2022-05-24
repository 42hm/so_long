/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 21:48:47 by hmoon             #+#    #+#             */
/*   Updated: 2022/05/24 09:27:59 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

void	so_long(t_mlx *mlx)
{
	init_mlx(mlx);
}

int	main(int ac, char **av)
{
	t_mlx	*mlx;
	int		i;

	i = 0;
	is_file_compatibility(ac, av);
	mlx = alloc_mlx();
	is_map_compatibility(av[1], mlx->map);
	make_bonus(mlx->map);
	so_long(mlx);
}
