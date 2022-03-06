/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_vert_wall_hit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:41:38 by user42            #+#    #+#             */
/*   Updated: 2022/03/06 16:31:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

static t_point	find_intercept(const t_ray *ray, const t_point *player_pos)
{
	t_point	intercept;

	intercept.x = floor(player_pos->x / TILE_SIZE) * TILE_SIZE;
	if (ray->is_facing_right)
		intercept.x += TILE_SIZE;
	intercept.y = \
	    player_pos->y + (intercept.x - player_pos->x) * tan(ray->angle);
	return (intercept);
}

static double	get_xstep(const t_ray *ray)
{
	double	xstep;

	xstep = TILE_SIZE;
	if (ray->is_facing_left)
		xstep *= -1;
	return (xstep);
}

static double	get_ystep(const t_ray *ray)
{
	double	ystep;

	ystep = TILE_SIZE * tan(ray->angle);
	if (ray->is_facing_up && ystep > 0)
		ystep *= -1;
	if (ray->is_facing_down && ystep < 0)
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

	while (intercept.x >= 0 && intercept.x <= WINDOW_WIDTH && \
	       intercept.y >= 0 && intercept.y <= WINDOW_HEIGHT)
	{
		check_x = intercept.x;
		if (ray->is_facing_left)
			check_x -= 1;
		check_y = intercept.y;
		if (map_has_wall_at(check_x, check_y, map->map_ptr))
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

t_point	find_vert_wall_hit(const t_ray *ray, const t_point *player_pos,
			const t_map *map)
{
	t_point	intercept;
	t_point	wall_hit;

	intercept = find_intercept(ray, player_pos);
	wall_hit = find_wall_hit(ray, map, intercept);
	return (wall_hit);
}
