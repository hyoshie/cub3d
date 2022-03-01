/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 13:05:28 by user42            #+#    #+#             */
/*   Updated: 2022/03/01 11:29:36 by user42           ###   ########.fr       */
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
#define YELLOW 0x00FFFF00
#define ORANGE 0x00FF6500
#define GRAY 0x002F3128
#define OFFWHITE 0x00FFF9EE

#define KEY_ESC 0xff1b
#define KEY_A 0x61
#define KEY_D 0x64
#define KEY_S 0x73
#define KEY_W 0x77

#define KEY_PRESS 2
#define KEY_RELEASE 3
#define KEY_PRESS_MASK (1L << 0)
#define KEY_RELEASE_MASK (1L << 1)

#define PLAYER_RADIUS 5
#define WALK_SPEED 10
#define TURN_SPEED (45 * (M_PI / 180))
// after turn around, walking back cause error
// #define PI 3.14159265
// #define TURN_SPEED (30 * (M_PI / 180))
// #define TURN_SPEED (30 * (PI / 180))

#define CENTER_LINE_LENGTH 60
#define FOV_ANGLE (60 * (M_PI / 180))
// #define FOV_ANGLE (60 * (PI / 180))
#define NUM_RAYS 4
#define RAY_LENGTH 100

#endif /* CONSTANTS_H */
