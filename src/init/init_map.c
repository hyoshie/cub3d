/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:25:22 by yshimazu          #+#    #+#             */
/*   Updated: 2022/03/10 13:20:31 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

//for test, check
void	print_clst(t_clst *lst)
{
	t_clst	*p;

	p = lst->next;
	while (p != lst)
	{
		printf("%s", p->content);
		printf(" : %zu\n", ft_strlen(p->content));
		p = p->next;
	}
}

t_clst	*adjast_cols(t_clst *map_lst, size_t map_cols)
{
	t_clst	*p;
	t_clst	*adjasted_lst;
	char	*spaces;
	size_t	content_len;

	p = map_lst->next;
	adjasted_lst = clst_new(NULL);
	while (p != map_lst)
	{
		content_len = ft_strlen(p->content);
		if (content_len != map_cols)
		{
			spaces = xmalloc(sizeof(char) * (map_cols - content_len + 1));
			spaces = ft_memset(spaces, ' ', map_cols - content_len);
			spaces[map_cols - content_len] = '\0';
			clst_addback(adjasted_lst,
				clst_new(ft_xstrjoin(p->content, spaces)));
			free(spaces);
		}
		else
			clst_addback(adjasted_lst, clst_new(ft_xstrdup(p->content)));
		p = p->next;
	}
	clst_clear(map_lst);
	return (adjasted_lst);
}

//たぶんここの初期化はいらない
//構造体初期化の時点で初期化できてるかを確認してこちら必要なければ削除
static void	set_map_width_height(t_clst *map_lst, t_map *map, size_t num_nodes)
{
	t_clst	*p;
	size_t	line_len;

	map->num_rows = num_nodes;
	map->height = map->num_rows * TILE_SIZE;
	map->num_cols = 0;
	map->width = 0;
	p = map_lst->next;
	while (p != map_lst)
	{
		line_len = ft_strlen(p->content);
		if (line_len * TILE_SIZE > map->width)
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
	map_lst = adjast_cols(map_lst, map->num_cols);
	print_clst(map_lst);
	map->map_ptr = clst_to_array(map_lst, map->height);
	validate_map(map->map_ptr);
}
