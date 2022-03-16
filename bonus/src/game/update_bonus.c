/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:36:52 by user42            #+#    #+#             */
/*   Updated: 2022/03/16 11:08:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants_bonus.h"
#include "cub3d_bonus.h"

static bool	is_in_range(int n, int begin, int end)
{
	return (n >= begin && n < end);
}

static void	rotate_player_angle(void *mlx_ptr, void *win_ptr, t_player *player)
{
	int	x;
	int	y;

	if (!player->should_rotate)
		return ;
	mlx_mouse_get_pos(mlx_ptr, win_ptr, &x, &y);
	if (is_in_range(x, 0, WINDOW_WIDTH / 3)
		&& is_in_range(y, 0, WINDOW_HEIGHT))
	{
		player->angle -= player->auto_turn_speed;
	}
	if (is_in_range(x, WINDOW_WIDTH / 3 * 2, WINDOW_WIDTH)
		&& is_in_range(y, 0, WINDOW_HEIGHT))
	{
		player->angle += player->auto_turn_speed;
	}
}

static bool	point_equals(t_point *p1, t_point *p2)
{
	return (p1->x == p2->x && p1->y == p2->y);
}

static void	move_player(t_player *player, t_map *map, t_minimap *mini)
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
		mini->player_pos.x = player->pos.x * mini->scale;
		mini->player_pos.y = player->pos.y * mini->scale;
	}
	else
	{
		if (!point_equals(&check, &player->wall_hit))
			ft_putendl_fd(MSG_WALL_COLLISION, STDERR_FILENO);
		player->wall_hit = check;
	}
}

void	update(t_game *game)
{
	rotate_player_angle(game->mlx_ptr, game->win_ptr, &game->player);
	if (game->player.should_move)
	{
		move_player(&game->player, &game->map, &game->mini);
	}
	cast_all_rays(game->ray, &game->player, &game->map);
}
