/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 02:37:12 by hmoon             #+#    #+#             */
/*   Updated: 2022/05/24 03:03:05 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include "../mlx/mlx.h"

enum e_handle
{
	A = 0,
	S = 1,
	D = 2,
	W = 13,
	ESC = 53,
	BITSIZE = 64,
	LEFT = 123,
	RIGHT = 124,
	DOWN = 125,
	UP = 126,
};

typedef struct	s_map
{
	char		**maparr;
	int			width;
	int			height;
	int			cur_i;
	int			cur_j;
	void		*wall;
	void		*floor;
	void		*collect;
	void		*enemy;
	void		*player;
	void		*wayout;
}				t_map;

typedef struct	s_mlx
{
	int			x;
	int			y;
	int			loop;
	int			move_count;
	int			collect_num;
	char		cur_key;
	void		*mlx_ptr;
	void		*window;
	t_map		*map;
}				t_mlx;

#endif
