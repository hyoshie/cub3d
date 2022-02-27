/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:02:40 by user42            #+#    #+#             */
/*   Updated: 2022/02/28 00:06:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "minimap.h"

int main(void) {
  t_game game;

  init_game(&game);
  // paint_screen(&mlx, floor, wall);
  register_hooks(&game);
  // for (int i = 0; i <= MAP_NUM_ROWS; i++) {
  //   printf("game.map->map_ptr[%d]%s\n", i, game.map->map_ptr[i]);
  // }
  mlx_loop(game.mlx_ptr);
  return (0);
}
