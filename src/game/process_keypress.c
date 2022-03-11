/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_keypress.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:25:13 by user42            #+#    #+#             */
/*   Updated: 2022/03/11 12:00:15 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

static bool	is_move_key(int keycode)
{
	if (keycode == KEY_W || keycode == KEY_A || \
		keycode == KEY_S || keycode == KEY_D)
	{
		return (true);
	}
	else
	{
		return (false);
	}
}

static bool	is_rotate_key(int keycode)
{
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		return (true);
	}
	else
	{
		return (false);
	}
}

static void	process_move_key(int keycode, t_player *player)
{
	player->should_move = true;
	if (keycode == KEY_W)
	{
		player->walk_direction = 0;
	}
	if (keycode == KEY_A)
	{
		player->walk_direction = -M_PI / 2;
	}
	if (keycode == KEY_S)
	{
		player->walk_direction = M_PI;
	}
	if (keycode == KEY_D)
	{
		player->walk_direction = M_PI / 2;
	}
}

static void	process_rotate_key(int keycode, t_player *player)
{
	if (keycode == KEY_LEFT)
	{
		player->angle -= player->turn_speed;
		player->angle = normalize_angle(player->angle);
	}
	if (keycode == KEY_RIGHT)
	{
		player->angle += player->turn_speed;
		player->angle = normalize_angle(player->angle);
	}
}

void	process_key_press(int keycode, t_player *player, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		free_all_exit(EM_ESC, game);
	}
	if (is_move_key(keycode))
	{
		process_move_key(keycode, player);
	}
	if (is_rotate_key(keycode))
	{
		process_rotate_key(keycode, player);
	}
}
