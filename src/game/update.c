/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:36:52 by user42            #+#    #+#             */
/*   Updated: 2022/03/09 10:29:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

static void	move_player(t_player *player, t_map *map)
{
	const int	move_step = player->walk_speed;
	double		move_angle;
	t_point		next;
	t_point		check;

	if (!player->should_move)
		return ;
	move_angle = player->rotation_angle + player->walk_direction;
	move_angle = normalize_angle(move_angle);
	next.x = player->position.x + cos(move_angle) * move_step;
	next.y = player->position.y + sin(move_angle) * move_step;
	check.x = next.x;
	check.y = next.y;
	if (move_angle > M_PI && move_angle < M_PI * 2)
		check.y -= 1;
	if (move_angle > 0.5 * M_PI && move_angle < 1.5 * M_PI)
		check.x -= 1;
	if (!map_has_wall_at(check.x, check.y, map))
	{
		player->position.x = next.x;
		player->position.y = next.y;
	}
}

void	update(t_game *game)
{
	move_player(&game->player, &game->map);
	cast_all_rays(game->ray, &game->player, &game->map);
}
