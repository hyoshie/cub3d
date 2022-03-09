/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:25:22 by yshimazu          #+#    #+#             */
/*   Updated: 2022/03/09 13:30:13 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

static void	set_map_width_height(t_clst *map_lst, t_map *map, size_t num_nodes)
{
	t_clst	*p;
	size_t	line_len;

	map->num_rows = num_nodes;
	map->height = map->num_rows * TILE_SIZE;
	map->num_cols = 0;
	p = map_lst->next;
	while (p != map_lst)
	{
		line_len = ft_strlen(p->content);
		if (line_len > map->width)
		{
			map->num_cols = line_len;
			map->width = map->num_cols * TILE_SIZE;
		}
		p = p->next;
	}
}

void	init_map(t_map *map, t_clst *map_lst, size_t num_nodes)
{
	set_map_width_height(map_lst, map, num_nodes);
	map->map_ptr = clst_to_array(map_lst, map->height);
	validate_map(map->map_ptr);
}
