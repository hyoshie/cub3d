/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texel_color_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:21:36 by user42            #+#    #+#             */
/*   Updated: 2022/03/16 11:09:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants_bonus.h"
#include "cub3d_bonus.h"

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

static int	get_pixel_from_texture(t_texture *tex, int x, int y)
{
	int		color;
	char	*color_addr;

	color_addr = \
		tex->addr + (y * tex->size_line + x * (tex->bits_per_pixel / 8));
	color = *(unsigned int *)color_addr;
	return (color);
}

static int	calc_texture_offset_x(t_ray *ray, t_texture *texture)
{
	int	tex_offset_x;
	int	left_edge;

	if (ray->wall_direction == NORTH)
	{
		tex_offset_x = (int)ray->wall_hit.x % TILE_SIZE;
	}
	else if (ray->wall_direction == SOUTH)
	{
		left_edge = ((int)ray->wall_hit.x / TILE_SIZE + 1) * TILE_SIZE - 1;
		tex_offset_x = left_edge - (int)ray->wall_hit.x;
	}
	else if (ray->wall_direction == WEST)
	{
		left_edge = ((int)ray->wall_hit.y / TILE_SIZE + 1) * TILE_SIZE - 1;
		tex_offset_x = left_edge - (int)ray->wall_hit.y;
	}
	else
	{
		tex_offset_x = (int)ray->wall_hit.y % TILE_SIZE;
	}
	tex_offset_x *= ((double)texture->width / TILE_SIZE);
	return (tex_offset_x);
}

int	get_texel_color(t_wall_strip strip, int y, t_ray *ray, t_texture *texture)
{
	int	color;
	int	tex_offset_x;
	int	tex_offset_y;
	int	distance_from_top;

	tex_offset_x = calc_texture_offset_x(ray, texture);
	distance_from_top = y + (strip.height / 2) - (WINDOW_HEIGHT / 2);
	tex_offset_y = distance_from_top * ((double)texture->height / strip.height);
	color = get_pixel_from_texture(texture, tex_offset_x, tex_offset_y);
	if (ray->distance > START_SHADING_DISTANCE)
		color = add_shade(color, START_SHADING_DISTANCE / ray->distance);
	return (color);
}
