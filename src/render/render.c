/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 23:22:31 by user42            #+#    #+#             */
/*   Updated: 2022/03/09 19:45:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

//デバック用です。
// static void	put_map(char **map)
// {
// 	printf("---------------------\n");
// 	for (int i = 0; map[i] ; i++) {
// 		printf("%s\n", map[i]);
// 	}
// }

int	render(t_game *game)
{
	t_img	win_img;

	init_image(&win_img, game->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	render_3d_projection(game, &win_img);
	render_minimap(&game->mini, &game->player, game->ray, &win_img);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			win_img.img_ptr, 0, 0);
	return (0);
}
