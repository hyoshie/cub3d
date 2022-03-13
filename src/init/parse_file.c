/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:25:32 by user42            #+#    #+#             */
/*   Updated: 2022/03/13 16:48:03 by yshimazu         ###   ########.fr       */
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
		else if (num_lines < sep_line)
		{
			if (line[0] == '\0')
			{
				free(line);
				continue ;
			}
			clst_addback(clst1, clst_new(line));
		}
		else
			clst_addback(clst2, clst_new(line));
		num_lines++;
	}
	return (num_lines);
}

void	file_path_to_lsts(char *file_path, t_parse *parse, size_t sep_line)
{
	parse->fd = ft_open_readfile(file_path);
	parse->num_lines = fd_to_clsts(parse->fd, parse->design_lst, parse->map_lst, sep_line);
	close(parse->fd);
}

void	parse_file(char *file_path, t_game *game, void *mlx_ptr)
{
	t_parse	parse;

	parse.design_lst = clst_new(NULL);
	parse.map_lst = clst_new(NULL);
	parse.file_lst = clst_new(NULL);
	path_to_lst();
	//path_to_design_lst(file_path, &parse, NUM_DESIGN_ELEMS);
	//path_to_map_lst(file_path, &parse, NUM_DESIGN_ELEMS);
	init_map(&game->map, parse.map_lst, parse.num_lines - NUM_DESIGN_ELEMS, game);
	init_design(&game->design, parse.design_lst, mlx_ptr, game);
	init_player(&game->player, game->map.map_ptr, game);
}
