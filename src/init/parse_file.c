/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:25:32 by user42            #+#    #+#             */
/*   Updated: 2022/03/11 12:08:57 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

/* //for test
void	print_clst(t_clst *lst)
{
	t_clst	*p;

	p = lst->next;
	while (p != lst)
	{
		ft_putstr_fd(p->content, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		p = p->next;
	}
}

//for test
void	print_array(char **array)
{
	int y;
	y = 0;
	while (array[y])
	{
		printf("%s\n", array[y]);
		y++;
	}
} */

int	ft_open_readfile(char *readfile)
{
	int	fd;

	fd = open(readfile, O_RDONLY);
	if (fd == -1)
		xperror(EM_OPEN);
	return (fd);
}

size_t	fd_to_clsts(int fd, t_clst *clst1, t_clst *clst2, size_t sep_line)
{
	char	*line;
	size_t	num_lines;
	int		gnl_ret;

	num_lines = 0;
	while (1)
	{
		gnl_ret = get_next_line(fd, &line);
		if (gnl_ret == 0)
			break ;
		if (gnl_ret == -1)
			xperror(EM_GNL);
		if (line[0] == '\0')
		{
			free(line);
			continue ;
		}
		else if (num_lines < sep_line)
			clst_addback(clst1, clst_new(line));
		else
			clst_addback(clst2, clst_new(line));
		num_lines++;
	}
	return (num_lines);
}

size_t	path_to_lsts(char *file_path, t_clst *design_lst,
		t_clst *map_lst, size_t sep_line)
{
	int		fd;
	size_t	num_lines;

	fd = ft_open_readfile(file_path);
	num_lines = fd_to_clsts(fd, design_lst, map_lst, sep_line);
	close(fd);
	return (num_lines);
}

void	parse_file(char *file_path, t_game *game, void *mlx_ptr)
{
	t_clst	*design_lst;
	t_clst	*map_lst;
	size_t	num_lines;

	design_lst = clst_new(NULL);
	map_lst = clst_new(NULL);
	num_lines = path_to_lsts(file_path, design_lst, map_lst, NUM_DESIGN_ELEMS);
	init_map(&game->map, map_lst, num_lines - NUM_DESIGN_ELEMS, game);
	init_design(&game->design, design_lst, mlx_ptr, game);
	init_player(&game->player, game->map.map_ptr);
}
