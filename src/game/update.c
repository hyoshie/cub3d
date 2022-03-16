/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:36:52 by user42            #+#    #+#             */
/*   Updated: 2022/03/16 11:24:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

static void	move_player(t_player *player, t_map *map)
{
	double	move_angle;
	t_point	next;
	t_point	check;

	move_angle = normalize_angle(player->angle + player->walk_direction);
	next.x = player->pos.x + cos(move_angle) * MOVE_STEP;
	next.y = player->pos.y + sin(move_angle) * MOVE_STEP;
	check = next;
	if (move_angle > M_PI && move_angle < M_PI * 2)
		check.y -= 1;
	if (move_angle > 0.5 * M_PI && move_angle < 1.5 * M_PI)
		check.x -= 1;
	if (!map_has_wall_at(check.x, check.y, map))
	{
		player->pos = next;
	}
	else
	{
		player->wall_hit = check;
	}
}

void	update(t_game *game)
{
	if (game->player.should_move)
	{
		move_player(&game->player, &game->map);
	}
	cast_all_rays(game->ray, &game->player, &game->map);
}
