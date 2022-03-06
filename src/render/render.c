/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 23:22:31 by user42            #+#    #+#             */
/*   Updated: 2022/03/06 15:08:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "minimap.h"

static void	render_ray(const t_point *player_pos, double ray_distance, \
					   double ray_angle, t_img *win_img)
{
	int	ray_x;
	int	ray_y;
	int	i;

	i = 0;
	while (i < ray_distance * MINIMAP_SCALE)
	{
		ray_x = player_pos->x * MINIMAP_SCALE + cos(ray_angle) * i;
		ray_y = player_pos->y * MINIMAP_SCALE + sin(ray_angle) * i;
		my_mlx_pixel_put(win_img, ray_x, ray_y, YELLOW);
		i++;
	}
}

static void	render_all_rays(t_player *player, t_ray *ray, t_img *win_img)
{
	double	ray_angle;
	int		i;

	ray_angle = player->rotation_angle - (player->fov_angle / 2);
	i = 0;
	while (i < NUM_RAYS)
	{
		render_ray(&player->position, ray[i++].distance, ray_angle, win_img);
		ray_angle += player->fov_angle / (NUM_RAYS - 1);
	}
}

static void	render_player(const t_player *player, t_img *win_img)
{
	int	i;
	int	j;

	i = -player->radius;
	while (i < player->radius)
	{
		j = -player->radius;
		while (j < player->radius)
		{
			if (pow(j, 2) + pow(i, 2) < pow(player->radius, 2))
				my_mlx_pixel_put(win_img, \
								 player->position.x * MINIMAP_SCALE + j, \
								 player->position.y * MINIMAP_SCALE + i, RED);
			j++;
		}
		i++;
	}
}

static void	render_minimap(t_map *map, t_player *player,
		t_ray *ray, t_img *win_img)
{
	render_map(map, win_img);
	render_all_rays(player, ray, win_img);
	render_player(player, win_img);
}

int	render(t_game *game)
{
	t_img	win_img;

	init_image(&win_img, game->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	render_3d_projection(&game->player, game->ray, &win_img);
	render_minimap(&game->map, &game->player, game->ray, &win_img);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
							win_img.img_ptr, 0, 0);
	return (0);
}
