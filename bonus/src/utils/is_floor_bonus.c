/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_floor_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:15:49 by user42            #+#    #+#             */
/*   Updated: 2022/03/16 11:09:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants_bonus.h"
#include "cub3d_bonus.h"

bool	is_floor(char c)
{
	return (c == '0' || is_player(c));
}
