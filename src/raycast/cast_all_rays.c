/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_all_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:19:01 by user42            #+#    #+#             */
/*   Updated: 2022/03/04 20:33:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "minimap.h"

static double normalize_angle(double ray_angle) {
  double normalized_angle = remainder(ray_angle, M_PI * 2);
  if (normalized_angle < 0)
    normalized_angle += M_PI * 2;
  return (normalized_angle);
}

static void set_ray_is_facing_to(t_ray *ray, double ray_angle) {
  double normalized_angle = normalize_angle(ray_angle);

  ray->angle = normalized_angle;
  ray->is_facing_up = normalized_angle > M_PI && normalized_angle < M_PI * 2;
  ray->is_facing_down = !ray->is_facing_up;
  ray->is_facing_left =
      normalized_angle > 0.5 * M_PI && normalized_angle < 1.5 * M_PI;
  ray->is_facing_right = !ray->is_facing_left;
}

void show_is_facing_to(t_ray *ray) {
  (void)ray;
  // printf("[up]	%d\n", ray->is_facing_up);
  // printf("[down]	%d\n", ray->is_facing_down);
  // printf("[left]	%d\n", ray->is_facing_left);
  // printf("[right]	%d\n", ray->is_facing_right);
}

static void cast_ray(t_ray *ray, double ray_angle, t_player *player,
                   const char  **map) {
  t_point horizontal_intersection;
  t_point vertical_intersection;

  set_ray_is_facing_to(ray, ray_angle);
  horizontal_intersection =
      find_horizontal_intersection(ray, &player->position, map);
  vertical_intersection =
      find_vertical_intersection(ray, &player->position, map);
  set_closer_intersection(ray, &horizontal_intersection, &vertical_intersection,
                          &player->position);
  // printf("[close.x ]%f\n", ray->wall_hit.x);
  // printf("[close.y ]%f\n", ray->wall_hit.y);
}

void cast_all_rays(t_ray *ray, t_player *player, const char **map) {
  // double ray_angle = player->rotation_angle - (FOV_ANGLE / 2);
  double ray_angle = player->rotation_angle - (player->fov_angle / 2);

  for (int strip_id = 0; strip_id < NUM_RAYS; strip_id++) {
    // printf("-----ID:%d-----\n", strip_id);
    cast_ray(&ray[strip_id], ray_angle, player, map);
    show_is_facing_to(&ray[strip_id]);
    ray_angle += player->fov_angle / (NUM_RAYS - 1);
  };
  // printf("------------------\n");
}
