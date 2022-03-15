/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:51:37 by user42            #+#    #+#             */
/*   Updated: 2022/03/14 18:44:40 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

void	free_all_exit(char *exit_message, t_game *game)
{
	if (game->mlx_ptr && game->design.north.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->design.north.img_ptr);
	if (game->mlx_ptr && game->design.south.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->design.south.img_ptr);
	if (game->mlx_ptr && game->design.west.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->design.west.img_ptr);
	if (game->mlx_ptr && game->design.east.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->design.east.img_ptr);
	if (game->mlx_ptr && game->win_img.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->win_img.img_ptr);
	if (game->mlx_ptr && game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		mlx_loop_end(game->mlx_ptr);
	}
	free(game->mlx_ptr);
	free(game->ray);
	free_vector(game->map.map_ptr);
	ft_putstr_fd(exit_message, STDERR_FILENO);
	exit (EXIT_SUCCESS);
}
