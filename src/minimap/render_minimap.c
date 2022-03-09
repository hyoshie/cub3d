/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:33:02 by user42            #+#    #+#             */
/*   Updated: 2022/03/09 19:10:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

static void	render_player(t_minimap *mini, t_img *win_img)
{
	int	i;
	int	j;

	i = -mini->player_radius;
	while (i < mini->player_radius)
	{
		j = -mini->player_radius;
		while (j < mini->player_radius)
		{
			if (pow(j, 2) + pow(i, 2) < pow(mini->player_radius, 2))
				my_mlx_pixel_put(win_img,
						mini->player_pos.x + j, mini->player_pos.y + i, RED);
			j++;
		}
		i++;
	}
}

static void	render_tile(t_minimap *mini, t_img *win_img, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < mini->tile_size)
	{
		j = 0;
		while (j < mini->tile_size)
		{
			my_mlx_pixel_put(win_img, x * mini->tile_size + j, \
							 y * mini->tile_size + i, mini->color);
			j++;
		}
		i++;
	}
}

static void	render_wall(t_minimap *mini, t_img *win_img)
{
	size_t	i;
	size_t	j;

	mini->color = GRAY;
	i = 0;
	while (i < mini->map->num_rows)
	{
		j = 0;
		while (j < mini->map->num_cols)
		{
			if (mini->map->map_ptr[i][j] == '1')
			{
				render_tile(mini, win_img, j, i);
			}
			j++;
		}
		i++;
	}
}

static bool	is_floor(char **map, int x, int y)
{
	return (map[y][x] == '0' \
			|| map[y][x]  == 'N' \
			|| map[y][x]  == 'S' \
			|| map[y][x]  == 'W' \
			|| map[y][x]  == 'E');
}

static void	render_floor(t_minimap *mini, t_img *win_img)
{
	size_t	i;
	size_t	j;

	mini->color = LIGHTGRAY;
	i = 0;
	while (i < mini->map->num_rows)
	{
		j = 0;
		while (j < mini->map->num_cols)
		{
			if (is_floor(mini->map->map_ptr, j, i))
			{
				render_tile(mini, win_img, j, i);
			}
			j++;
		}
		i++;
	}
}

void	render_minimap(t_minimap *mini, t_player *player, t_ray *ray, t_img *win_img)
{
	render_floor(mini, win_img);
	render_all_ray(mini, player, ray, win_img);
	render_player(mini, win_img);
	render_wall(mini, win_img);
}
