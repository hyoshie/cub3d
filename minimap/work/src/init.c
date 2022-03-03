/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 13:15:28 by user42            #+#    #+#             */
/*   Updated: 2022/03/03 22:20:09 by user42           ###   ########.fr       */
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

static void	init_monocolor_image(t_img *img, void *mlx_ptr, int color)
{
	int	i;
	int	j;

	init_image(img, mlx_ptr, TILE_SIZE, TILE_SIZE);
	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			my_mlx_pixel_put(img, j, i, color);
			j++;
		}
		i++;
	}
}

// temporary map
char *g_map[MAP_NUM_ROWS + 1] = {"11111111111111111111", "10000000000000000001",
                                 "10000000000000000001", "10001010101010101001",
                                 "10000000000000000001", "10000000000000001001",
                                 "10000000000000001001", "10000000000000001001",
                                 "10000000000001111001", "10000000000000000001",
                                 "10000000000000000001", "10000000000000000001",
                                 "11111111111111111111", NULL};

static void	init_map(t_map *map, void *mlx_ptr)
{
	map->map_ptr = g_map;
	init_monocolor_image(&map->floor, mlx_ptr, LIGHTGRAY);
	init_monocolor_image(&map->wall, mlx_ptr, GRAY);
}

static void	init_player(t_player *player)
{
	player->position.x = WINDOW_WIDTH / 2;
	player->position.y = WINDOW_HEIGHT / 2;
	player->radius = PLAYER_RADIUS;
	player->walk_direction = 0;
	player->turn_direction = 0;
	player->rotation_angle = M_PI / 2 * 3;
	player->fov_angle = 60 * (M_PI / 180);
	player->walk_speed = WALK_SPEED;
	player->turn_speed = 15 * (M_PI / 180);
}

// TODO:check calloc or malloc
static void	init_ray(t_ray **ray, t_player *player, t_map *map)
{
	*ray = calloc(sizeof(t_ray), NUM_RAYS);
	cast_all_rays(*ray, player, map);
}

void	init_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = \
		mlx_new_window(game->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
	init_map(&game->map, game->mlx_ptr);
	init_player(&game->player);
	init_ray(&game->ray, &game->player, &game->map);
}
