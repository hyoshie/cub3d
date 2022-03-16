/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 13:15:28 by user42            #+#    #+#             */
/*   Updated: 2022/03/16 11:08:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants_bonus.h"
#include "cub3d_bonus.h"

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
	int		i;

	*ray = ft_calloc(sizeof(t_ray), NUM_RAYS);
	i = 0;
	while (i < NUM_RAYS)
	{
		(*ray)[i].light_source = &player->pos;
		i++;
	}
	cast_all_rays(*ray, player, map);
}

void	init_game(t_game *game, char *file_path)
{
	*game = (t_game){0};
	game->mlx_ptr = xmlx_init();
	parse_file(file_path, game, game->mlx_ptr);
	game->win_ptr = \
		xmlx_new_window(game->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT, WINDOW_NAME);
	init_image(&game->win_img, game->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	init_ray(&game->ray, &game->player, &game->map);
	init_minimap(&game->mini, &game->map, game->player.pos);
}
