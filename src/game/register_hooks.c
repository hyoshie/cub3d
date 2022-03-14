/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:29:08 by user42            #+#    #+#             */
/*   Updated: 2022/03/13 14:49:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

//関数名がしっくりこない
static int	reset_key_press(int keycode, t_game *game)
{
	(void)keycode;
	game->player.walk_direction = 0;
	game->player.should_move = false;
	return (0);
}

static int	close_window(t_game *game)
{
	free_all_exit(EM_ESC, game);
	return (0);
}

static int	update_screen(t_game *game)
{
	update(game);
	render(game);
	return (0);
}

static int	toggle_auto_rotate(int button, int x, int y, t_player *player)
{
	(void)button;
	(void)x;
	(void)y;
	player->should_rotate = !player->should_rotate;
	return (0);
}

void	register_hooks(t_game *game)
{
	mlx_hook
		(game->win_ptr, KEY_PRESS, KEY_PRESS_MASK, process_key_press, game);
	mlx_hook
		(game->win_ptr, KEY_RELEASE, KEY_RELEASE_MASK, reset_key_press, game);
	mlx_hook
		(game->win_ptr, WIN_DESTROY, STRUCTURE_NOTIFY_MASK, close_window, game);
	mlx_expose_hook(game->win_ptr, render, game);
	mlx_loop_hook(game->mlx_ptr, update_screen, game);
	mlx_mouse_hook(game->win_ptr, toggle_auto_rotate, &game->player);
}
