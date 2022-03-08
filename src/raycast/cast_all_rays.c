/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_all_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:19:01 by user42            #+#    #+#             */
/*   Updated: 2022/03/08 10:37:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

static double	normalize_angle(double ray_angle)
{
	double	normalized_angle;

	normalized_angle = remainder(ray_angle, M_PI * 2);
	if (normalized_angle < 0)
		normalized_angle += M_PI * 2;
	return (normalized_angle);
}

static void	set_ray_is_facing_to(t_ray *ray, double ray_angle)
{
	ray->angle = normalize_angle(ray_angle);
	ray->is_facing_up = ray->angle > M_PI && ray->angle < M_PI * 2;
	ray->is_facing_down = !ray->is_facing_up;
	ray->is_facing_left = ray->angle > 0.5 * M_PI && ray->angle < 1.5 * M_PI;
	ray->is_facing_right = !ray->is_facing_left;
}

static void	cast_ray(t_ray *ray, double ray_angle, t_player *player,
										 t_map *map)
{
	t_point	horiz_wall_hit;
	t_point	vert_wall_hit;

	set_ray_is_facing_to(ray, ray_angle);
	horiz_wall_hit = find_horiz_wall_hit(ray, &player->position, map);
	vert_wall_hit = find_vert_wall_hit(ray, &player->position, map);
	set_closer_wall_hit(ray, &horiz_wall_hit, &vert_wall_hit,
		&player->position);
}

void	cast_all_rays(t_ray *ray, t_player *player, t_map *map)
{
	double	ray_angle;
	int		i;

	ray_angle = player->rotation_angle - (player->fov_angle / 2);
	i = 0;
	while (i < NUM_RAYS)
	{
		cast_ray(&ray[i], ray_angle, player, map);
		ray_angle += player->fov_angle / (NUM_RAYS - 1);
		i++;
	}
}
