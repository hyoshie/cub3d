/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:25:32 by user42            #+#    #+#             */
/*   Updated: 2022/03/14 10:46:52 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

//for test
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
}

int	ft_open_readfile(char *readfile)
{
	int	fd;

	fd = open(readfile, O_RDONLY);
	if (fd == -1)
		xperror(EM_OPEN);
	return (fd);
}

int	fd_to_clst(int fd, t_clst *file_lst, t_game *game)
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
			free_all_exit(EM_GNL, game);
		num_nodes++;
		clst_addback(file_lst, clst_new(line));
	}
}

/* void	file_path_to_lsts(char *file_path, t_parse *parse, size_t sep_line)
{
	parse->fd = ft_open_readfile(file_path);
	parse->num_lines = fd_to_clsts(parse->fd, parse->design_lst, parse->map_lst, sep_line);
	close(parse->fd);
} */

int	path_to_clst(char *file_path, t_clst *file_lst, t_game *game)
{
	int	fd;
	int	num_nodes;

	fd = ft_open_readfile(file_path);
	num_nodes = fd_to_clst(fd, file_lst, game);
	close(fd);
	return (num_nodes);
}

bool	is_map_line(char *line)
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

int	check_map_start(t_clst *file_lst)
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

void	validate_file(t_clst *file_lst, int map_start_line, t_game *game)
{
	//delete later
	(void)file_lst;
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
	(void)mlx_ptr;

	file_lst = clst_new(NULL);
	num_nodes = path_to_clst(file_path, file_lst, game);
	map_start_line = check_map_start(file_lst);
	validate_file(file_lst, map_start_line, game);
	//path_to_design_lst(file_path, &parse, NUM_DESIGN_ELEMS);
	//path_to_map_lst(file_path, &parse, NUM_DESIGN_ELEMS);
	init_design(file_lst, map_start_line - 1, mlx_ptr, game);
	clst_clear(file_lst);
	//printf("%d\n", num_nodes);
	//init_map(file_lst, map_start_line, num_nodes, game);
	//print_array(game->map.map_ptr);
	//init_player(&game->player, game->map.map_ptr, game);
	exit(0);
}
