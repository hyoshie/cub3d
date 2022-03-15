/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_closed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:20:58 by yshimazu          #+#    #+#             */
/*   Updated: 2022/03/14 21:49:19 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

static int	count_array_rows(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

static char	**array_dup(char **array)
{
	char	**copy;
	int		i;
	int		num_rows;

	i = 0;
	num_rows = count_array_rows(array);
	copy = (char **)xmalloc((sizeof(char *)) * (num_rows + 1));
	while (array[i])
	{
		copy[i] = ft_strdup(array[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static bool	is_all_sides_closed(char **map, int x, int y)
{
	if (!map[y] || map[y][x] == ' ' || map[y][x] == '\0')
		return (false);
	if (map[y][x] == '1' || map[y][x] == '@')
		return (true);
	map[y][x] = '@';
	return (is_all_sides_closed(map, x + 1, y)
		&& is_all_sides_closed(map, x - 1, y)
		&& is_all_sides_closed(map, x, y + 1)
		&& is_all_sides_closed(map, x, y - 1));
}

void	check_map_closed(char **map, t_game *game)
{
	char	**copy;
	int		x;
	int		y;

	copy = array_dup(map);
	y = 0;
	while (copy[y])
	{
		x = 0;
		while (copy[y][x])
		{
			if (copy[y][x] == '0' || is_player(copy[y][x]))
			{
				if (!is_all_sides_closed(copy, x, y))
					free_all_exit(EM_MAP_NOT_CLOSED, game);
			}
			x++;
		}
		y++;
	}
	free_vector(copy);
}
