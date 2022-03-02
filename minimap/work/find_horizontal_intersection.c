/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_horizontal_intersection.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:41:38 by user42            #+#    #+#             */
/*   Updated: 2022/03/02 17:31:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "minimap.h"

static t_point find_closest_intersection(t_ray *ray, t_point *player_pos) {
  t_point intersection;

  intersection.y = floor(player_pos->y / TILE_SIZE) * TILE_SIZE;
  if (ray->is_facing_down)
    intersection.y += TILE_SIZE;
  intersection.x =
      player_pos->x + (intersection.y - player_pos->y) / tan(ray->angle);
  return (intersection);
}

static double get_xstep(t_ray *ray) {
  double xstep;

  xstep = TILE_SIZE / tan(ray->angle);
  if (ray->is_facing_left && xstep > 0)
    xstep *= -1;
  if (ray->is_facing_right && xstep < 0)
    xstep *= -1;
  return (xstep);
}

static double get_ystep(t_ray *ray) {
  double ystep;

  ystep = TILE_SIZE;
  if (ray->is_facing_up)
    ystep *= -1;
  return (ystep);
}
//??
//     float yToCheck = nextHorzTouchY + (isRayFacingUp ? -1 : 0);
//        horzWallContent = map[(int)floor(yToCheck /
//        TILE_SIZE)][(int)floor(xToCheck / TILE_SIZE)]; foundHorzWallHit =
//        TRUE; break;
static t_point find_intersection_with_wall(t_ray *ray, t_map *map,
                                           t_point intersection) {
  const double xstep = get_xstep(ray);
  const double ystep = get_ystep(ray);
  double check_x;
  double check_y;

  while (intersection.x >= 0 && intersection.x <= WINDOW_WIDTH &&
         intersection.y >= 0 && intersection.y <= WINDOW_HEIGHT) {
    check_x = intersection.x;
    check_y = intersection.y;
    if (ray->is_facing_up)
      check_y -= 1;
    if (map_has_wall_at(check_x, check_y, map->map_ptr)) {
      return (intersection);
    } else {
      intersection.x += xstep;
      intersection.y += ystep;
    };
  }
  intersection.x = INFINITY;
  intersection.y = INFINITY;
  return (intersection);
}

t_point find_horizontal_intersection(t_ray *ray, t_point *player_pos,
                                     t_map *map) {
  t_point closest_intersection;
  t_point intersection_with_wall;

  closest_intersection = find_closest_intersection(ray, player_pos);
  intersection_with_wall =
      find_intersection_with_wall(ray, map, closest_intersection);
  return (intersection_with_wall);
}
