/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_angle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:34:59 by user42            #+#    #+#             */
/*   Updated: 2022/03/08 21:35:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

double	normalize_angle(double ray_angle)
{
	double	normalized_angle;

	normalized_angle = remainder(ray_angle, M_PI * 2);
	if (normalized_angle < 0)
		normalized_angle += M_PI * 2;
	return (normalized_angle);
}
