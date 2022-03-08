/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 00:05:42 by user42            #+#    #+#             */
/*   Updated: 2022/03/08 22:14:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

static t_wall_strip	get_wall_strip_info(t_ray *ray, t_player *player)
{
	t_wall_strip	strip;
	double			distance_projetion;
	double			perp_distance;

	distance_projetion = (WINDOW_WIDTH / 2) / tan(player->fov_angle / 2);
	perp_distance = \
	ray->distance * cos(ray->angle - player->rotation_angle);
	strip.height = (TILE_SIZE / perp_distance) * distance_projetion;
	strip.top_pixel = (WINDOW_HEIGHT / 2) - (strip.height / 2);
	if (strip.top_pixel < 0)
		strip.top_pixel = 0;
	strip.bottom_pixel = (WINDOW_HEIGHT / 2) + (strip.height / 2);
	if (strip.bottom_pixel > WINDOW_HEIGHT)
		strip.bottom_pixel = WINDOW_HEIGHT;
	return (strip);
}

static t_texture	*select_texture(t_ray *ray, t_design *design)
{
	if (ray->was_hit_vertical)
	{
		if (ray->is_facing_left)
			return (&design->west);
		else
			return (&design->east);
	}
	else
	{
		if (ray->is_facing_up)
			return (&design->north);
		else
			return (&design->south);
	}
}

static void	render_wall_strip(t_img *win_img, t_game *game, int x)
{
	t_wall_strip	strip;
	t_texture		*texture;
	int				color;
	int				y;

	strip = get_wall_strip_info(&game->ray[x], &game->player);
	y = 0;
	while (y < strip.top_pixel)
	{
		my_mlx_pixel_put(win_img, x, y++, game->design.ceil);
	}
	while (y < strip.bottom_pixel)
	{
		texture = select_texture(&game->ray[x], &game->design);
		color = get_texel_color(strip, y, &game->ray[x], texture);
		my_mlx_pixel_put(win_img, x, y++, color);
	}
	while (y < WINDOW_HEIGHT)
	{
		my_mlx_pixel_put(win_img, x, y++, game->design.floor);
	}
}

void	render_3d_projection(t_game *game, t_img *win_img)
{
	int		i;

	i = 0;
	while (i < NUM_RAYS)
	{
		render_wall_strip(win_img, game, i++);
	}
}
