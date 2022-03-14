/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_vert_wall_hit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:41:38 by user42            #+#    #+#             */
/*   Updated: 2022/03/14 01:53:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

static t_point	find_intercept(t_ray *ray)
{
	t_point	intercept;

	intercept.x = floor(ray->light_source.x / TILE_SIZE) * TILE_SIZE;
	if (ray->is_facing_right)
		intercept.x += TILE_SIZE;
	intercept.y = ray->light_source.y + \
					(intercept.x - ray->light_source.x) * tan(ray->angle);
	return (intercept);
}

static double	get_xstep(t_ray *ray)
{
	double	xstep;

	xstep = TILE_SIZE;
	if (ray->is_facing_left)
		xstep *= -1;
	return (xstep);
}

static double	get_ystep(t_ray *ray)
{
	double	ystep;

	ystep = TILE_SIZE * tan(ray->angle);
	if (ray->is_facing_up && ystep > 0)
		ystep *= -1;
	if (ray->is_facing_down && ystep < 0)
		ystep *= -1;
	return (ystep);
}

static t_point	find_wall_hit(t_ray *ray, t_map *map, t_point intercept)
{
	const double	xstep = get_xstep(ray);
	const double	ystep = get_ystep(ray);
	t_point			check;

	while (intercept.x >= 0 && intercept.x <= map->width && \
	       intercept.y >= 0 && intercept.y <= map->height)
	{
		check = intercept;
		if (ray->is_facing_left)
			check.x -= 1;
		if (map_has_wall_at(check.x, check.y, map))
		{
			return (intercept);
		}
		else
		{
			intercept.x += xstep;
			intercept.y += ystep;
		}
	}
	intercept.x = INFINITY;
	intercept.y = INFINITY;
	return (intercept);
}

t_point	find_vert_wall_hit(t_ray *ray, t_map *map)
{
	t_point	intercept;
	t_point	wall_hit;

	intercept = find_intercept(ray);
	wall_hit = find_wall_hit(ray, map, intercept);
	return (wall_hit);
}
