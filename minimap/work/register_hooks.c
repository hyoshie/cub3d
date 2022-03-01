/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:29:08 by user42            #+#    #+#             */
/*   Updated: 2022/03/01 10:32:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "minimap.h"

static int map_has_wall_at(int x, int y, char **map) {
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

  int next_player_x = player->x + cos(player->rotation_angle) * move_step;
  int next_player_y = player->y + sin(player->rotation_angle) * move_step;

  if (!map_has_wall_at(next_player_x, next_player_y, map)) {
    player->x = next_player_x;
    player->y = next_player_y;
  }
}

static int key_press_hook(int keycode, t_game *game) {
  if (keycode == KEY_ESC) {
    printf("(｡-ω-)ﾉsee you again… \n");
    exit(EXIT_SUCCESS);
  } else if (keycode == KEY_W) {
    game->player.walk_direction = 1;
  } else if (keycode == KEY_A) {
    game->player.turn_direction = -1;
  } else if (keycode == KEY_S) {
    game->player.walk_direction = -1;
  } else if (keycode == KEY_D) {
    game->player.turn_direction = 1;
  }
  move_player(&game->player, game->map.map_ptr);
  render(game);
  return (0);
}

static int key_release_hook(int keycode, t_game *game) {
  (void)keycode;
  game->player.walk_direction = 0;
  game->player.turn_direction = 0;
  return (0);
}

void register_hooks(t_game *game) {
  mlx_expose_hook(game->win_ptr, render, game);
  mlx_hook(game->win_ptr, KEY_PRESS, KEY_PRESS_MASK, key_press_hook, game);
  mlx_hook(game->win_ptr, KEY_RELEASE, KEY_RELEASE_MASK, key_release_hook,
           game);
  // mlx_loop_hook(game->mlx_ptr, render, game);
}
