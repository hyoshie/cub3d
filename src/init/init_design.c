/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_design.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 20:44:41 by user42            #+#    #+#             */
/*   Updated: 2022/03/07 15:59:29by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

static void	load_xpm_file(void *mlx_ptr, t_texture *direction, char *file_path)
{
	direction->img_ptr = mlx_xpm_file_to_image(mlx_ptr, file_path,
			&direction->width, &direction->height);
	direction->addr = \
			mlx_get_data_addr(direction->img_ptr, &direction->bits_per_pixel,
			&direction->size_line, &direction->endian);
}

// 色もとりあえずここで初期化しています。
void	init_design(void *mlx_ptr, t_design *design)
{
	load_xpm_file(mlx_ptr, &design->north, "texture/manf1.xpm");
	load_xpm_file(mlx_ptr, &design->south, "texture/manb1.xpm");
	load_xpm_file(mlx_ptr, &design->west, "texture/ove.xpm");
	load_xpm_file(mlx_ptr, &design->east, "texture/castle.xpm");
	design->ceil = SKYBLUE;
	design->floor = KOGETYA;
}

void	design_lst_to_dict(t_clst *design_lst, t_dict *path, char sep)
{
	t_clst	*lst_ptr;
	char	**vector;

	lst_ptr = design_lst->next;
	while (lst_ptr != design_lst)
	{
		vector = ft_xsplit(lst_ptr->content, sep);
		/* if (vector[2])
			exit(1);//エラー処理する */
		dict_addback(path, dict_new(vector[0], vector[1]));
		lst_ptr = lst_ptr->next;
	}
	free_vector(vector);
}

void	set_design(void *mlx_ptr, t_design *design, t_clst *design_lst)
{
	t_dict	*path;

	path = dict_new(NULL, NULL);
	design_lst_to_dict(design_lst, path, ' ');
	load_xpm_file(mlx_ptr, &design->north, dict_get_value("NO", path));
	load_xpm_file(mlx_ptr, &design->south, dict_get_value("SO", path));
	load_xpm_file(mlx_ptr, &design->west, dict_get_value("WE", path));
	load_xpm_file(mlx_ptr, &design->east, dict_get_value("EA", path));
	//rgb_to_hex();
	/* design->ceil = ft_atoi(dict_get_value("C", path));
	design->floor = ft_atoi(dict_get_value("F", path)); */
}