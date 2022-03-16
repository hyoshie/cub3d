/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_player_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:29:07 by yshimazu          #+#    #+#             */
/*   Updated: 2022/03/16 11:08:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants_bonus.h"
#include "cub3d_bonus.h"

void	validate_player(char **map_ptr)
{
	int	y;
	int	x;
	int	num_player;

	y = 0;
	num_player = 0;
	while (map_ptr[y])
	{
		x = 0;
		while (map_ptr[y][x])
		{
			if (is_player(map_ptr[y][x]))
			{
				num_player++;
				if (num_player > 1)
					error_exit(EM_MANY_PLAYERS);
			}
			x++;
		}
		y++;
	}
	if (num_player == 0)
		error_exit(EM_NO_PLAYER);
}
