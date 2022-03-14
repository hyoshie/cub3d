/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:29:07 by yshimazu          #+#    #+#             */
/*   Updated: 2022/03/14 11:16:46 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

void	validate_player(char **map_ptr, t_game *game)
{
	size_t	y;
	size_t	x;
	int		num_player;

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
					free_all_exit(EM_MANY_PLAYERS, game);
			}
			x++;
		}
		y++;
	}
	if (num_player == 0)
		free_all_exit(EM_NO_PLAYER, game);
}
