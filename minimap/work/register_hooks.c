/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:29:08 by user42            #+#    #+#             */
/*   Updated: 2022/03/01 11:39:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "minimap.h"

static void process_key_press(int keycode, t_player *player) {
  if (keycode == KEY_ESC) {
    printf("(｡-ω-)ﾉsee you again… \n");
    exit(EXIT_SUCCESS);
  } else if (keycode == KEY_W) {
    player->walk_direction = 1;
  } else if (keycode == KEY_A) {
    player->turn_direction = -1;
  } else if (keycode == KEY_S) {
    player->walk_direction = -1;
  } else if (keycode == KEY_D) {
    player->turn_direction = 1;
  }
}

static int key_press_hook(int keycode, t_game *game) {
  process_key_press(keycode, &game->player);
  update(game);
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
