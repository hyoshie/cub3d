/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 13:05:28 by user42            #+#    #+#             */
/*   Updated: 2022/02/28 00:45:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
#define CONSTANTS_H

#define TILE_SIZE 32
#define MAP_NUM_COLS 20
#define MAP_NUM_ROWS 13
#define WINDOW_WIDTH (MAP_NUM_COLS * TILE_SIZE)
#define WINDOW_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)
#define WINDOW_NAME "####Minimap####"

#define RED 0x00FF0000
// #define GREEN 0x0000FF00
// #define BLUE 0x000000FF
#define GRAY 0x002F3128
#define OFFWHITE 0x00FFF9EE

#define KEY_ESC 0xff1b
#define KEY_A 0x61
#define KEY_D 0x64
#define KEY_S 0x73
#define KEY_W 0x77
#define STEP_X 10
#define STEP_Y 10

#endif /* CONSTANTS_H */
