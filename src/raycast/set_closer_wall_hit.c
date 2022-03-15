/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_closer_wall_hit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:41:29 by user42            #+#    #+#             */
/*   Updated: 2022/03/15 16:12:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

static double	get_distance(t_point *p1, t_point *p2)
{
	double	dx;
	double	dy;

	dx = p1->x - p2->x;
	dy = p1->y - p2->y;
	return (sqrt(dx * dx + dy * dy));
}

void	set_closer_wall_hit(t_ray *ray, t_point *horiz_hit, t_point *vert_hit)
{
	double	horiz_distance;
	double	vert_distance;

	horiz_distance = get_distance(horiz_hit, ray->light_source);
	vert_distance = get_distance(vert_hit, ray->light_source);
	if (horiz_distance < vert_distance)
	{
		ray->wall_hit = *horiz_hit;
		ray->distance = horiz_distance;
		ray->was_hit_vertical = false;
	}
	else
	{
		ray->wall_hit = *vert_hit;
		ray->distance = vert_distance;
		ray->was_hit_vertical = true;
	}
}
