/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 00:05:42 by user42            #+#    #+#             */
/*   Updated: 2022/03/06 16:31:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

static void	render_wall_strip(t_img *win_img, int x, double wall_height, \
							  int color)
{
	int	first;
	int	last;

	first = (WINDOW_HEIGHT / 2) - (wall_height / 2);
	last = first + wall_height;
	while (first < last)
	{
		my_mlx_pixel_put(win_img, x, first++, color);
	}
}

static int	add_shade(int color, double scale)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = (color >> 24) & 0xFF;
	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = (color >> 0) & 0xFF;
	r *= scale;
	g *= scale;
	b *= scale;
	return (t << 24 | r << 16 | g << 8 | b);
}

static int	get_strip_color(double ray_distance, bool was_hit_vertical)
{
	int	color;

	if (was_hit_vertical)
		color = YELLOW;
	else
		color = OFFWHITE;
	if (ray_distance > 100)
		color = add_shade(color, 100 / ray_distance);
	return (color);
}

//TODO:check why height over WINDOW_HEIGHT
void	render_3d_wall(t_player *player, t_ray *ray, t_img *win_img)
{
	double	distance_projetion;
	double	wall_height;
	double	perp_distance;
	int		wall_color;
	int		i;

	distance_projetion = (WINDOW_WIDTH / 2) / tan(player->fov_angle / 2);
	i = 0;
	while (i < NUM_RAYS)
	{
		perp_distance = \
			ray[i].distance * cos(ray[i].angle - player->rotation_angle);
		wall_height = (TILE_SIZE / perp_distance) * distance_projetion;
		if (wall_height > WINDOW_HEIGHT)
			wall_height = WINDOW_HEIGHT;
		wall_color = get_strip_color(ray[i].distance, ray[i].was_hit_vertical);
		render_wall_strip(win_img, i, wall_height, wall_color);
		i++;
	}
}
