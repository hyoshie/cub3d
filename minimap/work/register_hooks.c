/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:29:08 by user42            #+#    #+#             */
/*   Updated: 2022/02/28 17:25:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "minimap.h"

void move_player(t_player *player) {
  int move_step = player->walk_direction * player->walk_speed;

  player->rotation_angle += player->turn_direction * player->turn_speed;
  player->x += cos(player->rotation_angle) * move_step;
  player->y += sin(player->rotation_angle) * move_step;
}

static int key_press_hook(int keycode, t_game *game) {
  if (keycode == KEY_ESC) {
    printf("(｡-ω-)ﾉsee you again… \n");
    exit(EXIT_SUCCESS);
  } else if (keycode == KEY_W) {
    game->player.walk_direction = -1;
  } else if (keycode == KEY_A) {
    game->player.turn_direction = -1;
  } else if (keycode == KEY_S) {
    game->player.walk_direction = 1;
  } else if (keycode == KEY_D) {
    game->player.turn_direction = 1;
  }
  move_player(&game->player);
  render(game);
  return (0);
}

static int key_release_hook(int keycode, t_game *game) {
  (void)keycode;
  game->player.walk_direction = 0;
  game->player.turn_direction = 0;
  return (0);
}
// static int key_hook_handler(int keycode, t_game *game) {
//   mlx_do_key_autorepeaton(game->mlx_ptr);
//   if (keycode == KEY_ESC) {
//     printf("(｡-ω-)ﾉsee you again… \n");
//     exit(EXIT_SUCCESS);
//   } else if (keycode == KEY_W) {
//     game->player.y -= STEP_Y;
//   } else if (keycode == KEY_A) {
//     game->player.x -= STEP_X;
//   } else if (keycode == KEY_S) {
//     game->player.y += STEP_Y;
//   } else if (keycode == KEY_D) {
//     game->player.x += STEP_X;
//   }
//   render(game);
//   return (0);
// }

void register_hooks(t_game *game) {
  mlx_expose_hook(game->win_ptr, render, game);
  mlx_hook(game->win_ptr, KEY_PRESS, KEY_PRESS_MASK, key_press_hook, game);
  mlx_hook(game->win_ptr, KEY_RELEASE, KEY_RELEASE_MASK, key_release_hook,
           game);
  // mlx_key_hook(game->win_ptr, key_hook_handler, game);
  // mlx_loop_hook(game->mlx_ptr, render, game);
}
