/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:15:05 by yshimazu          #+#    #+#             */
/*   Updated: 2022/03/09 13:19:35 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

t_color	rgb_to_int(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

//TODO:all_free_exit的なエラーハンドリングにする
int	rgb_atoi(char *s)
{
	int	num;

	num = ft_atoi(s);
	if (num < 0 || num > 255)
		exit(1);
	return (num);
}