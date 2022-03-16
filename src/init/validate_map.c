/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:22:05 by yshimazu          #+#    #+#             */
/*   Updated: 2022/03/16 06:26:11 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

static bool	is_map_char(char c)
{
	if (ft_strchr("10 ", c))
		return (true);
	else
		return (false);
}

static void	check_map_char(char **map)
{
	int		x;
	int		y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!is_map_char(map[y][x]) && !is_player(map[y][x]))
				error_exit(EM_MAP_CHAR);
			x++;
		}
		y++;
	}
}

void	validate_map(t_map *map)
{
	if (map->num_cols > MAX_MAP_COLS || map->num_rows > MAX_MAP_ROWS)
		error_exit(EM_MAP_BIG);
	check_map_closed(map->map_ptr);
	check_map_char(map->map_ptr);
}
