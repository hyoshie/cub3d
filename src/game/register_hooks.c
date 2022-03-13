/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:29:08 by user42            #+#    #+#             */
/*   Updated: 2022/03/13 13:56:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

//I wanna change func name:process_key_press.
static int	key_press_hook(int keycode, t_game *game)
{
	process_key_press(keycode, &game->player, game);
	return (0);
}

static int	key_release_hook(int keycode, t_game *game)
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

void	register_hooks(t_game *game)
{
	mlx_hook(game->win_ptr, KEY_PRESS, KEY_PRESS_MASK, key_press_hook, game);
	mlx_hook(game->win_ptr, KEY_RELEASE, KEY_RELEASE_MASK,
		key_release_hook, game);
	mlx_hook(game->win_ptr, WIN_DESTROY, STRUCTURE_NOTIFY_MASK,
		close_window, game);
	mlx_expose_hook(game->win_ptr, render, game);
	mlx_loop_hook(game->mlx_ptr, update_screen, game);
}
