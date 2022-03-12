/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:36:52 by user42            #+#    #+#             */
/*   Updated: 2022/03/12 10:44:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

static void	move_player(t_player *player, t_map *map, t_minimap *mini)
{
	double		move_angle;
	t_point		next;
	t_point		check;

	if (!player->should_move)
		return ;
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
		mini->player_pos.x = player->pos.x * mini->scale;
		mini->player_pos.y = player->pos.y * mini->scale;
	}
	else
	{
		ft_putendl_fd(MSG_WALL_COLLISION, STDERR_FILENO);
	}
}

void	update(t_game *game)
{
	move_player(&game->player, &game->map, &game->mini);
	cast_all_rays(game->ray, &game->player, &game->map);
}
