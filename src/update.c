/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:36:52 by user42            #+#    #+#             */
/*   Updated: 2022/03/04 20:36:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "minimap.h"

bool	map_has_wall_at(double x, double y, const char **map)
{
	const int	map_grid_index_x = x / TILE_SIZE;
	const int	map_grid_index_y = y / TILE_SIZE;

	if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
	{
		return (true);
	}
	else
	{
		return (map[map_grid_index_y][map_grid_index_x] == '1');
	}
}

// static void	move_player(t_player *player, char **map)
// {
// 	const int	move_step = player->walk_direction * player->walk_speed;
// 	double		next_x;
// 	double		next_y;

// 	player->rotation_angle += player->turn_direction * player->turn_speed;
// 	next_x = player->position.x + cos(player->rotation_angle) * move_step;
// 	next_y = player->position.y + sin(player->rotation_angle) * move_step;
// 	if (!map_has_wall_at(next_x, next_y, map))
// 	{
// 		player->position.x = next_x;
// 		player->position.y = next_y;
// 	}
// }

static void	move_player(t_player *player, const char **map)
{
	const int	move_step = player->walk_speed;
	double		move_angle;
	double		next_x;
	double		next_y;

	if (!player->should_move)
		return ;
	move_angle = player->rotation_angle + player->walk_direction;
	next_x = player->position.x + cos(move_angle) * move_step;
	next_y = player->position.y + sin(move_angle) * move_step;
	if (!map_has_wall_at(next_x, next_y, map))
	{
		player->position.x = next_x;
		player->position.y = next_y;
	}
}

void	update(t_game *game)
{
	move_player(&game->player, (const char **)game->map);
	cast_all_rays(game->ray, &game->player, (const char **)game->map);
}
