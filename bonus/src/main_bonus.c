/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:02:40 by user42            #+#    #+#             */
/*   Updated: 2022/03/16 11:08:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants_bonus.h"
#include "cub3d_bonus.h"

int	main(int ac, char *av[])
{
	t_game	game;

	check_args(ac, av);
	init_game(&game, av[1]);
	register_hooks(&game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
