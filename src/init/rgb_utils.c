/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:54:15 by yshimazu          #+#    #+#             */
/*   Updated: 2022/03/15 16:54:15 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:15:05 by yshimazu          #+#    #+#             */
/*   Updated: 2022/03/11 14:42:56by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

t_color	rgb_to_int(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

//TODO:all_free_exit的なエラーハンドリングにする
int	rgb_atoi(char *s, t_game *game)
{
	int	num;
	int	digit;

	while (*s == ' ' || *s == '\f' || *s == '\n'
		|| *s == '\r' || *s == '\t' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
		free_design_exit(EM_RGB, game);
	num = 0;
	digit = 0;
	while (ft_isdigit(*s) && digit < 3)
	{
		num = (num * 10) + (*s - '0');
		s++;
		digit++;
	}
	if (*s != '\0' || num < 0 || num > 255)
		free_design_exit(EM_RGB, game);
	return (num);
}
