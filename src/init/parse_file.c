/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:25:32 by user42            #+#    #+#             */
/*   Updated: 2022/03/14 21:42:09 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

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

static void	validate_start_line(int map_start_line, t_game *game)
{
	if (map_start_line == -1)
		free_all_exit(EM_NO_MAP, game);
	if (map_start_line < NUM_DESIGN_ELEMS)
		free_all_exit(EM_DESIGN, game);
}

void	parse_file(char *file_path, t_game *game, void *mlx_ptr)
{
	t_clst	*file_lst;
	int		map_start_line;
	int		num_nodes;

	file_lst = clst_new(NULL);
	num_nodes = path_to_clst(file_path, file_lst, game);
	map_start_line = map_line_at(file_lst);
	validate_start_line(map_start_line, game);
	init_design(file_lst, map_start_line, mlx_ptr, game);
	init_map(file_lst, map_start_line, num_nodes, game);
	init_player(&game->player, game->map.map_ptr, game);
}
