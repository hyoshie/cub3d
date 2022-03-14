/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 23:22:31 by user42            #+#    #+#             */
/*   Updated: 2022/03/14 00:49:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

int	render(t_game *game)
{
	render_3d_projection(game, &game->win_img);
	render_minimap(&game->mini, game->ray, &game->win_img);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
								game->win_img.img_ptr, 0, 0);
	return (0);
}
