/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:36:52 by user42            #+#    #+#             */
/*   Updated: 2022/03/01 17:42:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "minimap.h"

static bool map_has_wall_at(double x, double y, char **map) {
  if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT) {
    return true;
  }
  int map_grid_index_x = x / TILE_SIZE;
  int map_grid_index_y = y / TILE_SIZE;
  return map[map_grid_index_y][map_grid_index_x] == '1';
}

static void move_player(t_player *player, char **map) {
  int move_step = player->walk_direction * player->walk_speed;
  player->rotation_angle += player->turn_direction * player->turn_speed;

  double next_player_x;
  double next_player_y;
  next_player_x = player->x + cos(player->rotation_angle) * move_step;
  next_player_y = player->y + sin(player->rotation_angle) * move_step;

  if (!map_has_wall_at(next_player_x, next_player_y, map)) {
    player->x = next_player_x;
    player->y = next_player_y;
  }
}

void update(t_game *game) {
  move_player(&game->player, game->map.map_ptr);
  // cast_all_rays(game->ray, &game->player);
}
