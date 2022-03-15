/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 13:15:28 by user42            #+#    #+#             */
/*   Updated: 2022/03/15 16:30:19 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

void	init_image(t_img *img, void *mlx_ptr, int width, int height)
{
	img->img_ptr = xmlx_new_image(mlx_ptr, width, height);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
			&img->size_line, &img->endian);
	img->width = width;
	img->height = height;
}

static void	init_ray(t_ray **ray, t_player *player, t_map *map)
{
	*ray = ft_calloc(sizeof(t_ray), NUM_RAYS);
	cast_all_rays(*ray, player, map);
}

void	init_game(t_game *game, char *file_path)
{
	*game = (t_game){0};
	game->mlx_ptr = xmlx_init();
	parse_file(file_path, &game->parse, game, game->mlx_ptr);
	game->win_ptr = \
		xmlx_new_window(game->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT, WINDOW_NAME);
	init_image(&game->win_img, game->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	init_ray(&game->ray, &game->player, &game->map);
	init_minimap(&game->mini, &game->map, game->player.pos);
}
