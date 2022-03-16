/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:24:49 by yshimazu          #+#    #+#             */
/*   Updated: 2022/03/16 11:08:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants_bonus.h"
#include "cub3d_bonus.h"

static int	ft_open_readfile(char *readfile)
{
	int	fd;

	fd = open(readfile, O_RDONLY);
	if (fd == -1)
		xperror(EM_OPEN);
	return (fd);
}

static int	fd_to_clst(int fd, t_clst *file_lst)
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
			error_exit(EM_GNL);
		num_nodes++;
		clst_addback(file_lst, clst_new(line));
	}
}

int	path_to_clst(char *file_path, t_clst *file_lst)
{
	int	fd;
	int	num_nodes;

	fd = ft_open_readfile(file_path);
	num_nodes = fd_to_clst(fd, file_lst);
	close(fd);
	return (num_nodes);
}
