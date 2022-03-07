/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:25:32 by user42            #+#    #+#             */
/*   Updated: 2022/03/07 14:56:17 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

//for test
void	print_clst(t_clst *lst)
{
	t_clst *p;
	p = lst->next;
	while(p != lst)
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
}

int	ft_open_readfile(char *readfile)
{
	int	fd;

	fd = open(readfile, O_RDONLY);
	if (fd == -1)
		xperror("open");
	return (fd);
}

size_t	fd_to_clsts(int fd, t_clst *clst1, t_clst *clst2, size_t sep_line)
{
	char	*line;
	size_t	num_lines;

	num_lines = 0;
	while (1)
	{
		line = gnl(fd);
		if (!line)
			break ;
		else if (num_lines < sep_line)
			clst_addback(clst1, clst_new(line));
		else
			clst_addback(clst2, clst_new(line));
		num_lines++;
	}
	return (num_lines);
}


void	set_map_width_height(t_clst *map_lst, t_map *map, size_t num_nodes)
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

size_t	path_to_lsts(char *file_path, t_clst *design_lst, t_clst *map_lst, size_t sep_line)
{
	int		fd;
	size_t	num_lines;

	fd = ft_open_readfile(file_path);
	num_lines = fd_to_clsts(fd, design_lst, map_lst, sep_line);
	close(fd);
	return (num_lines);
}

void	set_map(t_map *map, t_clst *map_lst, size_t num_nodes)
{
	set_map_width_height(map_lst, map, num_nodes);
	map->map_ptr = clst_to_array(map_lst, map->height);
}

void	parse_file(char *file_path, t_map *map, t_design *design, void *mlx_ptr)
{
	t_clst	*design_lst;
	t_clst	*map_lst;
	size_t	num_lines;

	design_lst = clst_new(NULL);
	map_lst = clst_new(NULL);
	num_lines = path_to_lsts(file_path, design_lst, map_lst, SEP_LINE);
	set_map(map, map_lst, num_lines - SEP_LINE);
	//check_map(map);
	set_design(mlx_ptr, design, design_lst);
	(void)design;
	(void)mlx_ptr;
	//clst_clear(map_lst);
	//clst_clear(design_lst);
	//printf("width: %zu, height: %zu\n", map->width, map->height);
	//print_array(map->map_ptr);
}