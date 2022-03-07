/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_design.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 20:44:41 by user42            #+#    #+#             */
/*   Updated: 2022/03/07 14:56:10 by yshimazu         ###   ########.fr       */
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

void	set_design(void *mlx_ptr, t_design *design, t_clst *design_lst)
{
	load_xpm_file(mlx_ptr, &design->north, "texture/manf1.xpm");
	load_xpm_file(mlx_ptr, &design->south, "texture/manb1.xpm");
	load_xpm_file(mlx_ptr, &design->west, "texture/ove.xpm");
	load_xpm_file(mlx_ptr, &design->east, "texture/castle.xpm");
	design->ceil = SKYBLUE;
	design->floor = KOGETYA;
	(void)design_lst;
}