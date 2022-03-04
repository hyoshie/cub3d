/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 00:05:42 by user42            #+#    #+#             */
/*   Updated: 2022/03/04 14:51:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "minimap.h"

static void	render_3d_ceil(t_img *win_img)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT / 2)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(win_img, j, i, SKYBLUE);
			j++;
		}
		i++;
	}

}

static void	render_3d_floor(t_img *win_img)
{
	int	i;
	int	j;

	printf("[\x1b[32mPASS\x1b[39m]\n");
	i = WINDOW_HEIGHT / 2;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(win_img, j, i, KOGETYA);
			j++;
		}
		i++;
	}

}
void	render_3d_projection(t_player *player, t_ray *ray, t_img *win_img)
{
	render_3d_ceil(win_img);
	render_3d_floor(win_img);
	render_3d_wall(player, ray, win_img);
}
