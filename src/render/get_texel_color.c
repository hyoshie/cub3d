/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:21:36 by user42            #+#    #+#             */
/*   Updated: 2022/03/08 14:22:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

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

int	get_texel_color(t_wall_strip strip, int y, t_ray *ray, t_texture *texture)
{
	int	color;
	int	tex_offset_x;
	int	tex_offset_y;
	int	distance_from_top;

	if (ray->was_hit_vertical)
		tex_offset_x = (int)ray->wall_hit.y % TILE_SIZE;
	else
		tex_offset_x = (int)ray->wall_hit.x % TILE_SIZE;
	tex_offset_x *= ((double)texture->height / TILE_SIZE);
	distance_from_top = y + (strip.height / 2) - (WINDOW_HEIGHT / 2);
	tex_offset_y = distance_from_top * ((double)texture->height / strip.height);
	if (ray->was_hit_vertical)
		color = get_pixel_from_texture(texture, tex_offset_x, tex_offset_y);
	else
		color = get_pixel_from_texture(texture, tex_offset_x, tex_offset_y);
	if (ray->distance > 100)
		color = add_shade(color, 100 / ray->distance);
	return (color);
}
