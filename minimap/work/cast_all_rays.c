/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_all_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:19:01 by user42            #+#    #+#             */
/*   Updated: 2022/03/02 11:59:19 by user42           ###   ########.fr       */
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

// static void set_ray_is_facing_to(t_ray *ray, double ray_angle, int strip_id)
// {
//   double normalized_angle = normalize_angle(ray_angle);

//   ray[strip_id].angle = normalized_angle;
//   ray[strip_id].is_facing_up =
//       normalized_angle > M_PI && normalized_angle < M_PI * 2;
//   ray[strip_id].is_facing_down = !ray[strip_id].is_facing_up;
//   ray[strip_id].is_facing_left =
//       normalized_angle > 0.5 * M_PI && normalized_angle < 1.5 * M_PI;
//   ray[strip_id].is_facing_right = !ray[strip_id].is_facing_left;
// }

static void set_ray_is_facing_to(t_ray *ray, double ray_angle) {
  double normalized_angle = normalize_angle(ray_angle);

  ray->angle = normalized_angle;
  ray->is_facing_up = normalized_angle > M_PI && normalized_angle < M_PI * 2;
  ray->is_facing_down = !ray->is_facing_up;
  ray->is_facing_left =
      normalized_angle > 0.5 * M_PI && normalized_angle < 1.5 * M_PI;
  ray->is_facing_right = !ray->is_facing_left;
}

// float xintercept, yintercept;
// float xstep, ystep;

/////////////////////////////////////////////
//// HORIZONTAL RAY-GRID INTERSECTION CODE
/////////////////////////////////////////////
// int foundHorzWallHit = FALSE;
// float horzWallHitX = 0;
// float horzWallHitY = 0;
// int horzWallContent = 0;

//// Find the y-coordinate of the closest horizontal grid intersection
// yintercept = floor(player.y / TILE_SIZE) * TILE_SIZE;
// yintercept += isRayFacingDown ? TILE_SIZE : 0;

//// Find the x-coordinate of the closest horizontal grid intersection
// xintercept = player.x + (yintercept - player.y) / tan(rayAngle);

//// Calculate the increment xstep and ystep
// ystep = TILE_SIZE;
// ystep *= isRayFacingUp ? -1 : 1;

// xstep = TILE_SIZE / tan(rayAngle);
// xstep *= (isRayFacingLeft && xstep > 0) ? -1 : 1;
// xstep *= (isRayFacingRight && xstep < 0) ? -1 : 1;

// float nextHorzTouchX = xintercept;
// float nextHorzTouchY = yintercept;

//// Increment xstep and ystep until we find a wall
// while (nextHorzTouchX >= 0 && nextHorzTouchX <= WINDOW_WIDTH &&
// nextHorzTouchY >= 0 && nextHorzTouchY <= WINDOW_HEIGHT) {
//     float xToCheck = nextHorzTouchX;
//     float yToCheck = nextHorzTouchY + (isRayFacingUp ? -1 : 0);

//    if (mapHasWallAt(xToCheck, yToCheck)) {
//        // found a wall hit
//        horzWallHitX = nextHorzTouchX;
//        horzWallHitY = nextHorzTouchY;
//        horzWallContent = map[(int)floor(yToCheck /
//        TILE_SIZE)][(int)floor(xToCheck / TILE_SIZE)]; foundHorzWallHit =
//        TRUE; break;
//    } else {
//        nextHorzTouchX += xstep;
//        nextHorzTouchY += ystep;
//    }
//}

// static t_point find_horizontal_intersection(t_ray *ray, double ray_angle,
//                                             int strip_id) {
//   bool found_intersection;
//   t_point closest_intersection;
//   t_point intersection_with_wall;

//   found_intersection = false;
//   // find_closest_intersection();
//   // find_intersection_with_wall();
//   if (found_intersection) {
//     return intersection_with_wall;
//   } else {
//     return ((t_point){INFINITY, INFINITY});
//   }
// }

void show_is_facing_to(t_ray *ray, int strip_id) {
  printf("-----ID:%d-----\n", strip_id);
  printf("[up]	%d\n", ray[strip_id].is_facing_up);
  printf("[down]	%d\n", ray[strip_id].is_facing_down);
  printf("[left]	%d\n", ray[strip_id].is_facing_left);
  printf("[right]	%d\n", ray[strip_id].is_facing_right);
}

static void cast_ray(t_ray *ray, double ray_angle, int strip_id) {
  // t_point horizontal_intersection;
  // t_point vertical_intersection;

  // set_ray_is_facing_to(ray, ray_angle, strip_id);
  set_ray_is_facing_to(&ray[strip_id], ray_angle);
  show_is_facing_to(ray, strip_id);

  // find_horizontal_intersection();
  // find_vertical_intersection();
  // set_closer_intersection();
}

void cast_all_rays(t_ray *ray, t_player *player) {
  double ray_angle = player->rotation_angle - (FOV_ANGLE / 2);

  for (int strip_id = 0; strip_id < NUM_RAYS; strip_id++) {
    cast_ray(ray, ray_angle, strip_id);
    ray_angle += FOV_ANGLE / (NUM_RAYS - 1);
  };
  printf("------------------\n");
}
