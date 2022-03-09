/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 13:05:28 by user42            #+#    #+#             */
/*   Updated: 2022/03/09 12:59:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

# define TILE_SIZE 32
# define MAP_NUM_COLS 20
# define MAP_NUM_ROWS 13
# define WINDOW_WIDTH 640
# define WINDOW_HEIGHT 416
# define WINDOW_ASPECT_RATIO 0.65
# define WINDOW_NAME "####Cub3D####"
# define MINIMAP_SCALE 0.25
# define MINIMAP_WIDTH_MAX 160
# define MINIMAP_HEIGHT_MAX 104

# define RED 0x00FF0000
# define YELLOW 0x00FFFF00
# define ORANGE 0x00FF6500
# define GRAY 0x002F3128
# define LIGHTGRAY 0x00D3D3D3
# define OFFWHITE 0x00FFF9EE
# define BLACK 0x00000000
# define SKYBLUE 0x0090D7EC
# define KOGETYA 0x006A4332

# define KEY_ESC 0xff1b
# define KEY_A 0x61
# define KEY_D 0x64
# define KEY_S 0x73
# define KEY_W 0x77
# define KEY_LEFT 0xff51
# define KEY_RIGHT 0xff53

# define KEY_PRESS 2
# define KEY_RELEASE 3
# define KEY_PRESS_MASK 1
# define KEY_RELEASE_MASK 2

# define PLAYER_RADIUS 10
# define WALK_SPEED 10

# define NUM_RAYS WINDOW_WIDTH

# define NUM_DESIGN_LINES 6

#endif /* CONSTANTS_H */
