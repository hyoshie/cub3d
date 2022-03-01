/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_all_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:19:01 by user42            #+#    #+#             */
/*   Updated: 2022/03/01 15:02:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "minimap.h"

// void castRay(float rayAngle, int stripId) {
//     rayAngle = normalizeAngle(rayAngle);

//     int isRayFacingDown = rayAngle > 0 && rayAngle < PI;
//     int isRayFacingUp = !isRayFacingDown;

//     int isRayFacingRight = rayAngle < 0.5 * PI || rayAngle > 1.5 * PI;
//     int isRayFacingLeft = !isRayFacingRight;

// float normalizeAngle(float angle) {
//     angle = remainder(angle, TWO_PI);
//     if (angle < 0) {
//         angle = TWO_PI + angle;
//     }
//     return angle;
// }

// static void set_ray_info(t_ray *ray, double ray_angle, int strip_id) {
//   ray[strip_id].angle = ray_angle;
//   ray[strip_id].is_facing_up = ray_angle > M_PI && ray_angle < M_PI * 2;
//   ray[strip_id].is_facing_down = !ray[strip_id].is_facing_up;
//   ray[strip_id].is_facing_left =
//       ray_angle > 0.5 * M_PI || ray_angle < 1.5 * M_PI;
//   ray[strip_id].is_facing_right = !ray[strip_id].is_facing_left;
// }

// static void cast_ray(t_ray *ray, double ray_angle, int strip_id) {
//   (void)ray;
//   (void)ray_angle;
//   (void)strip_id;
//   // set_ray_info(ray, ray_angle, strip_id);
//   // find_horizontal_intersection();
//   // find_vertical_intersection();
//   // set_closer_intersection();
// }

// void cast_all_rays(t_ray *ray, t_player *player) {
//   double ray_angle = player->rotation_angle - (FOV_ANGLE / 2);

//   for (int strip_id = 0; strip_id < NUM_RAYS; strip_id++) {
//     cast_ray(ray, ray_angle, strip_id);
//     ray_angle += FOV_ANGLE / (NUM_RAYS - 1);
//   };
// }
