/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:25:32 by user42            #+#    #+#             */
/*   Updated: 2022/03/16 11:08:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants_bonus.h"
#include "cub3d_bonus.h"

static bool	is_map_line(char *line)
{
	if (*line == '\0')
		return (false);
	while (*line)
	{
		if (!ft_strchr(" 1", *line))
			return (false);
		line++;
	}
	return (true);
}

static int	map_line_at(t_clst *file_lst)
{
	int		map_start_line;
	t_clst	*p;

	map_start_line = 0;
	p = file_lst->next;
	while (p != file_lst)
	{
		if (is_map_line(p->content))
			return (map_start_line);
		map_start_line++;
		p = p->next;
	}
	return (-1);
}

static void	validate_start_line(int map_start_line)
{
	if (map_start_line == -1)
		error_exit(EM_NO_MAP);
	if (map_start_line < NUM_DESIGN_ELEMS)
		error_exit(EM_DESIGN);
}

void	parse_file(char *file_path, t_game *game, void *mlx_ptr)
{
	t_clst	*file_lst;
	int		map_start_line;
	int		num_nodes;

	file_lst = clst_new(NULL);
	num_nodes = path_to_clst(file_path, file_lst);
	map_start_line = map_line_at(file_lst);
	validate_start_line(map_start_line);
	init_design(file_lst, &game->design, map_start_line, mlx_ptr);
	init_map(file_lst, &game->map, map_start_line, num_nodes);
	init_player(game->map.map_ptr, &game->player);
}
