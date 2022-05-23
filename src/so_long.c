/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 21:48:47 by hmoon             #+#    #+#             */
/*   Updated: 2022/05/24 02:37:38 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

static void	is_file_compatibility(int ac, char **av)
{
	if (ac != 2)
		ft_error_exit("Error\nInvalid argument number");
	if (ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".ber", 4) != 0)
		ft_error_exit("Error\nInvalid file extension");
	if (ft_strlen(av[1]) < 5)
		ft_error_exit("Error\nInvalid file name");
}

int	main(int ac, char **av)
{
	is_file_compatibility(ac, av);
}
