/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:02:40 by user42            #+#    #+#             */
/*   Updated: 2022/02/28 16:08:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "minimap.h"

int main(void) {
  t_game game;

  init_game(&game);
  register_hooks(&game);
  mlx_loop(game.mlx_ptr);
  return (0);
}
