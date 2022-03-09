/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_horiz_wall_hit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:41:38 by user42            #+#    #+#             */
/*   Updated: 2022/03/09 11:04:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

static t_point	find_intercept(const t_ray *ray, const t_point *player_pos)
{
	t_point	intercept;

	intercept.y = floor(player_pos->y / TILE_SIZE) * TILE_SIZE;
	if (ray->is_facing_down)
		intercept.y += TILE_SIZE;
	intercept.x = player_pos->x + \
					(intercept.y - player_pos->y) / tan(ray->angle);
	return (intercept);
}

static double	get_xstep(const t_ray *ray)
{
	double	xstep;

	xstep = TILE_SIZE / tan(ray->angle);
	if (ray->is_facing_left && xstep > 0)
		xstep *= -1;
	if (ray->is_facing_right && xstep < 0)
		xstep *= -1;
	return (xstep);
}

static double	get_ystep(const t_ray *ray)
{
	double	ystep;

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
static t_point	find_wall_hit(const t_ray *ray, const t_map *map,
							  t_point intercept)
{
	const double	xstep = get_xstep(ray);
	const double	ystep = get_ystep(ray);
	double			check_x;
	double			check_y;

	while (intercept.x >= 0 && intercept.x <= map->width && \
	       intercept.y >= 0 && intercept.y <= map->height)
	{
		check_x = intercept.x;
		check_y = intercept.y;
		if (ray->is_facing_up)
			check_y -= 1;
		if (map_has_wall_at(check_x, check_y, (t_map *)map))
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

t_point	find_horiz_wall_hit(const t_ray *ray, const t_point *player_pos,
									 const t_map *map)
{
	t_point	intercept;
	t_point	wall_hit;

	intercept = find_intercept(ray, player_pos);
	wall_hit = find_wall_hit(ray, map, intercept);
	return (wall_hit);
}
