/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_design.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 20:44:41 by user42            #+#    #+#             */
/*   Updated: 2022/03/10 14:28:00 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

static void	load_xpm_file(void *mlx_ptr, t_texture *direction, char *file_path, t_game *game)
{
	direction->img_ptr = mlx_xpm_file_to_image(mlx_ptr, file_path,
			&direction->width, &direction->height);
	if (!direction->img_ptr)
		free_all_exit("Error: Can't read xpm file (Check your cub file)", game);
	direction->addr = \
			mlx_get_data_addr(direction->img_ptr, &direction->bits_per_pixel,
			&direction->size_line, &direction->endian);
}

static void	design_lst_to_dict(t_clst *design_lst,
	t_dict *design_dict, char sep)
{
	t_clst	*lst_ptr;
	char	**vector;

	lst_ptr = design_lst->next;
	while (lst_ptr != design_lst)
	{
		vector = ft_xsplit(lst_ptr->content, sep);
		if (!vector[0] || !vector[1])
		{
			lst_ptr = lst_ptr->next;
			free_vector(vector);
			continue ;
		}
		dict_addback(design_dict, dict_new(ft_xstrdup(vector[0]),
				ft_xstrdup(vector[1])));
		lst_ptr = lst_ptr->next;
		free_vector(vector);
	}
	clst_clear(design_lst);
}

static void	load_wall_xpm_files(void *mlx_ptr,
	t_design *design, t_dict *design_dict, t_game *game)
{
	load_xpm_file(mlx_ptr, &design->north, dict_get_value("NO", design_dict), game);
	load_xpm_file(mlx_ptr, &design->south, dict_get_value("SO", design_dict), game);
	load_xpm_file(mlx_ptr, &design->west, dict_get_value("WE", design_dict), game);
	load_xpm_file(mlx_ptr, &design->east, dict_get_value("EA", design_dict), game);
}

static void	load_ceil_floor_color(t_design *design, t_dict *design_dict, t_game *game)
{
	char	**c_vector;
	char	**f_vector;
	t_color	c_color;
	t_color	f_color;

	c_vector = ft_xsplit(dict_get_value("C", design_dict), ',');
	f_vector = ft_xsplit(dict_get_value("F", design_dict), ',');
	c_color = rgb_to_int(0, rgb_atoi(c_vector[0], game),
			rgb_atoi(c_vector[1], game), rgb_atoi(c_vector[2], game));
	f_color = rgb_to_int(0, rgb_atoi(f_vector[0], game),
			rgb_atoi(f_vector[1], game), rgb_atoi(f_vector[2], game));
	design->ceil = c_color;
	design->floor = f_color;
	free_vector(c_vector);
	free_vector(f_vector);
}
/* //for test
void	print_dict(t_dict *d)
{
	t_dict	*p;

	p = d->next;
	while (p != d)
	{
		printf("key: %s\n", p->key);
		printf("value: %s\n", p->value);
		p = p->next;
	}
} */

void	init_design(t_design *design, t_clst *design_lst, void *mlx_ptr, t_game *game)
{
	t_dict	*design_dict;

	design_dict = dict_new(NULL, NULL);
	design_lst_to_dict(design_lst, design_dict, ' ');
	validate_design(design_dict, game);
	load_wall_xpm_files(mlx_ptr, design, design_dict, game);
	load_ceil_floor_color(design, design_dict, game);
	dict_clear(design_dict);
}
