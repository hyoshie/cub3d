/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:29:08 by user42            #+#    #+#             */
/*   Updated: 2022/02/28 16:18:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "minimap.h"

static int key_hook_handler(int keycode, t_game *game) {
  mlx_do_key_autorepeaton(game->mlx_ptr);
  if (keycode == KEY_ESC) {
    printf("(｡-ω-)ﾉsee you again… \n");
    exit(EXIT_SUCCESS);
  } else if (keycode == KEY_W) {
    game->player.y -= STEP_Y;
  } else if (keycode == KEY_A) {
    game->player.x -= STEP_X;
  } else if (keycode == KEY_S) {
    game->player.y += STEP_Y;
  } else if (keycode == KEY_D) {
    game->player.x += STEP_X;
  }
  render(game);
  return (0);
}

void register_hooks(t_game *game) {
  mlx_key_hook(game->win_ptr, key_hook_handler, game);
  // mlx_loop_hook(game->mlx_ptr, render, game);
}
