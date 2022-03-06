/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_closer_wall_hit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:41:29 by user42            #+#    #+#             */
/*   Updated: 2022/03/06 16:31:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

static double	get_distance(const t_point *p1, const t_point *p2)
{
	double	dx;
	double	dy;

	dx = p1->x - p2->x;
	dy = p1->y - p2->y;
	return (sqrt(dx * dx + dy * dy));
}

void	set_closer_wall_hit(t_ray *ray, const t_point *horiz_wall_hit,
								const t_point *vert_wall_hit,
								const t_point *player_pos)
{
	double	horiz_distance;
	double	vert_distance;

	horiz_distance = get_distance(horiz_wall_hit, player_pos);
	vert_distance = get_distance(vert_wall_hit, player_pos);
	if (horiz_distance < vert_distance)
	{
		ray->wall_hit = *horiz_wall_hit;
		ray->distance = horiz_distance;
		ray->was_hit_vertical = false;
	}
	else
	{
		ray->wall_hit = *vert_wall_hit;
		ray->distance = vert_distance;
		ray->was_hit_vertical = true;
	}
}
