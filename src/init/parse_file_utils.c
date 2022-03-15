/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:24:49 by yshimazu          #+#    #+#             */
/*   Updated: 2022/03/15 16:53:38 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

static int	ft_open_readfile(char *readfile)
{
	int	fd;

	fd = open(readfile, O_RDONLY);
	if (fd == -1)
		xperror(EM_OPEN);
	return (fd);
}

//ここでfree(line)必要か検討
static int	fd_to_clst(int fd, t_clst *file_lst, t_game *game)
{
	char	*line;
	int		gnl_ret;
	int		num_nodes;

	num_nodes = 0;
	while (1)
	{
		gnl_ret = get_next_line(fd, &line);
		if (gnl_ret == 0)
			return (num_nodes);
		if (gnl_ret == -1)
			free_design_exit(EM_GNL, game);
		num_nodes++;
		clst_addback(file_lst, clst_new(line));
	}
}

int	path_to_clst(char *file_path, t_clst *file_lst, t_game *game)
{
	int	fd;
	int	num_nodes;

	fd = ft_open_readfile(file_path);
	num_nodes = fd_to_clst(fd, file_lst, game);
	close(fd);
	return (num_nodes);
}
