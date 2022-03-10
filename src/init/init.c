/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 13:15:28 by user42            #+#    #+#             */
/*   Updated: 2022/03/10 19:40:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

void	init_image(t_img *img, void *mlx_ptr, int width, int height)
{
	img->img_ptr = mlx_new_image(mlx_ptr, width, height);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
			&img->size_line, &img->endian);
	img->width = width;
	img->height = height;
}

// TODO:check calloc or malloc
static void	init_ray(t_ray **ray, t_player *player, t_map *map)
{
	*ray = calloc(sizeof(t_ray), NUM_RAYS);
	cast_all_rays(*ray, player, map);
}

// fileをparseしてからwindows作った方がエラーが出た時に一瞬画面が出るということがないので順番変えました
void	init_game(t_game *game, char *file_path)
{
	*game = (t_game){0};
	game->mlx_ptr = mlx_init();
	parse_file(file_path, game, game->mlx_ptr);
	game->win_ptr = \
		mlx_new_window(game->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
	init_image(&game->win_img, game->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	init_ray(&game->ray, &game->player, &game->map);
	init_minimap(&game->mini, &game->map, game->player.pos);
}
