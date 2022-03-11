/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:29:08 by user42            #+#    #+#             */
/*   Updated: 2022/03/11 23:50:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

//I wanna change func name:process_key_press.
static int	key_press_hook(int keycode, t_game *game)
{
	process_key_press(keycode, &game->player, game);
	update(game);
	render(game);
	return (0);
}

static int	key_release_hook(int keycode, t_game *game)
{
	(void)keycode;
	game->player.walk_direction = 0;
	game->player.should_move = false;
	return (0);
}

static int	mouse_click_hook(int button, int x, int y, t_game *game)
{
	(void)button;
	(void)y;
	game->player.angle = game->ray[x].angle;
	update(game);
	render(game);
	return (0);
}

static int	close_window(t_game *game)
{
	free_all_exit(EM_ESC, game);
	return (0);
}

// mlx_loop_hook(game->mlx_ptr, render, game);
void	register_hooks(t_game *game)
{
	mlx_hook(game->win_ptr, KEY_PRESS, KEY_PRESS_MASK, key_press_hook, game);
	mlx_hook(game->win_ptr, KEY_RELEASE, KEY_RELEASE_MASK, key_release_hook,
		game);
	mlx_hook(game->win_ptr, KEY_PRESS, KEY_PRESS_MASK, key_press_hook, game);
	mlx_hook(game->win_ptr, WIN_DESTROY, STRUCTURE_NOTIFY_MASK, close_window,
		game);
	mlx_expose_hook(game->win_ptr, render, game);
	mlx_mouse_hook(game->win_ptr, mouse_click_hook, game);
}
