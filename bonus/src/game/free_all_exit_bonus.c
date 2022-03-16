/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_exit_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:51:37 by user42            #+#    #+#             */
/*   Updated: 2022/03/16 11:08:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants_bonus.h"
#include "cub3d_bonus.h"

void	error_exit(char *message)
{
	ft_putendl_fd(message, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	free_all_exit(t_game *game)
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
	ft_putendl_fd(EM_ESC, STDERR_FILENO);
	exit (EXIT_SUCCESS);
}
