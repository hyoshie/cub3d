/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_horiz_wall_hit_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:41:38 by user42            #+#    #+#             */
/*   Updated: 2022/03/16 11:08:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants_bonus.h"
#include "cub3d_bonus.h"

static t_point	find_intercept(t_ray *ray)
{
	t_point	intercept;

	intercept.y = floor(ray->light_source->y / TILE_SIZE) * TILE_SIZE;
	if (ray->is_facing_down)
		intercept.y += TILE_SIZE;
	intercept.x = ray->light_source->x + \
					(intercept.y - ray->light_source->y) / tan(ray->angle);
	return (intercept);
}

static double	get_xstep(t_ray *ray)
{
	double	xstep;

	xstep = TILE_SIZE / tan(ray->angle);
	if (ray->is_facing_left && xstep > 0)
		xstep *= -1;
	if (ray->is_facing_right && xstep < 0)
		xstep *= -1;
	return (xstep);
}

static double	get_ystep(t_ray *ray)
{
	double	ystep;

	ystep = TILE_SIZE;
	if (ray->is_facing_up)
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
		if (ray->is_facing_up)
			check.y -= 1;
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

t_point	find_horiz_wall_hit(t_ray *ray, t_map *map)
{
	t_point	intercept;
	t_point	wall_hit;

	intercept = find_intercept(ray);
	wall_hit = find_wall_hit(ray, map, intercept);
	return (wall_hit);
}
