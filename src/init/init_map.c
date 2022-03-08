/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:25:22 by yshimazu          #+#    #+#             */
/*   Updated: 2022/03/08 15:18:46 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

static void	set_map_width_height(t_clst *map_lst, t_map *map, size_t num_nodes)
{
	t_clst	*p;
	size_t	line_len;

	map->height = num_nodes;
	map->width = 0;
	p = map_lst->next;
	while (p != map_lst)
	{
		line_len = ft_strlen(p->content);
		if (line_len > map->width)
			map->width = line_len;
		p = p->next;
	}
}

void	set_map(t_map *map, t_clst *map_lst, size_t num_nodes)
{
	set_map_width_height(map_lst, map, num_nodes);
	map->map_ptr = clst_to_array(map_lst, map->height);
}
