/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 13:15:28 by user42            #+#    #+#             */
/*   Updated: 2022/03/04 20:36:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "minimap.h"

void	init_image(t_img *img, void *mlx_ptr, int width, int height)
{
	img->img_ptr = mlx_new_image(mlx_ptr, width, height);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
			 &img->size_line, &img->endian);
}

// temporary map
char *g_map[MAP_NUM_ROWS + 1] = {"11111111111111111111", "10000000000000000001",
                                 "10000000000000000001", "10001010101010101001",
                                 "10000000000000000001", "10000000000000001001",
                                 "10000000000000001001", "10000000000000001001",
                                 "10000000000001111001", "10000000000000000001",
                                 "10000000000000000001", "10000000000000000001",
                                 "11111111111111111111", NULL};

static void	init_map(t_game *game)
{
	game->map = g_map;
	// init_monocolor_image(&map->floor, mlx_ptr, LIGHTGRAY);
	// init_monocolor_image(&map->wall, mlx_ptr, GRAY);
}

static void	init_player(t_player *player)
{
	player->position.x = WINDOW_WIDTH / 2;
	player->position.y = WINDOW_HEIGHT / 2;
	player->radius = PLAYER_RADIUS * MINIMAP_SCALE;
	player->walk_direction = 0;
	player->should_move = false;
	player->rotation_angle = M_PI / 2 * 3;
	player->fov_angle = 60 * (M_PI / 180);
	player->walk_speed = WALK_SPEED;
	player->turn_speed = 15 * (M_PI / 180);
}

// TODO:check calloc or malloc
static void	init_ray(t_ray **ray, t_player *player, const char **map)
{
	*ray = calloc(sizeof(t_ray), NUM_RAYS);
	cast_all_rays(*ray, player, map);
}

void	init_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = \
		mlx_new_window(game->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
	// init_map(&game->map, game->mlx_ptr);
	init_map(game);
	init_player(&game->player);
	init_ray(&game->ray, &game->player, (const char **)game->map);
}
