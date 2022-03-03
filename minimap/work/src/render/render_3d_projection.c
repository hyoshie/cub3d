/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 00:05:42 by user42            #+#    #+#             */
/*   Updated: 2022/03/04 00:50:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "minimap.h"

static void	render_wall_strip(t_img *win_img, int x, double wall_strip_height, \
							  int color)
{
	int	first;
	int	last;

	first =  (WINDOW_HEIGHT / 2) - (wall_strip_height / 2);
	last = first + wall_strip_height;
	while (first < last)
	{
		my_mlx_pixel_put(win_img, x, first++, color);
	}
}

//TODO:check why height over WINDOW_HEIGHT
void	render_3d_projection(t_player *player, t_ray *ray, t_img *win_img)
{
	double	distance_projetion;
	double	wall_strip_height;
	int	i;

	distance_projetion = (WINDOW_WIDTH / 2) / tan(player->fov_angle / 2);
	i = 0;
	while (i < NUM_RAYS)
	{
		wall_strip_height = (TILE_SIZE / ray[i].distance) * distance_projetion;
		if (wall_strip_height  > WINDOW_HEIGHT)
			wall_strip_height = WINDOW_HEIGHT;
		render_wall_strip(win_img, i, wall_strip_height, OFFWHITE);
		i++;
	}
}
