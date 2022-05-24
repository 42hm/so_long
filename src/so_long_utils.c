/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:02:27 by hmoon             #+#    #+#             */
/*   Updated: 2022/05/24 09:28:07 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

t_mlx	*alloc_mlx()
{
	t_mlx	*temp;

	temp = ft_malloc(sizeof(t_mlx));
	ft_memset(temp, 0, sizeof(t_mlx));
	temp->map = ft_malloc(sizeof(t_map));
	ft_memset(temp->map, 0, sizeof(t_map));
	return (temp);
}
