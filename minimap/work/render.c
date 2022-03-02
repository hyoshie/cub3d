/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 17:40:49 by user42            #+#    #+#             */
/*   Updated: 2022/03/02 15:57:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "minimap.h"

static void render_ray(t_player *player, t_img *win_img) {
  double ray_angle = player->rotation_angle - (FOV_ANGLE / 2);

  for (int i = 0; i < NUM_RAYS; i++) {
    for (int j = 0; j < RAY_LENGTH; j++) {
      int x = player->position.x + cos(ray_angle) * j;
      int y = player->position.y + sin(ray_angle) * j;
      my_mlx_pixel_put(win_img, x, y, YELLOW);
    };
    ray_angle += FOV_ANGLE / (NUM_RAYS - 1);
  }
}

static void render_center_line(t_player *player, t_img *win_img) {
  for (int i = 0; i < CENTER_LINE_LENGTH; i++) {
    int x = player->position.x + cos(player->rotation_angle) * i;
    int y = player->position.y + sin(player->rotation_angle) * i;
    my_mlx_pixel_put(win_img, x, y, RED);
  }
}

static void render_player(t_player *player, t_img *win_img) {
  for (int i = -player->radius; i < player->radius; i++) {
    for (int j = -player->radius; j < player->radius; j++) {
      if (pow(j, 2) + pow(i, 2) < pow(player->radius, 2))
        my_mlx_pixel_put(win_img, player->position.x + j,
                         player->position.y + i, RED);
    }
  }
  render_center_line(player, win_img);
}

int render(t_game *game) {
  t_img win_img;

  init_image(&win_img, game->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
  render_map(&game->map, &win_img);
  render_ray(&game->player, &win_img);
  render_player(&game->player, &win_img);
  mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, win_img.img_ptr, 0, 0);
  return (0);
}
