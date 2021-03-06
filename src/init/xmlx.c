/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmlx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:03:05 by yshimazu          #+#    #+#             */
/*   Updated: 2022/03/11 15:03:06 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

void	*xmlx_init(void)
{
	void	*ret;

	ret = mlx_init();
	if (!ret)
		xperror(EM_MLX);
	return (ret);
}

void	*xmlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title)
{
	void	*ret;

	ret = mlx_new_window(mlx_ptr, size_x, size_y, title);
	if (!ret)
		xperror(EM_MLX);
	return (ret);
}

void	*xmlx_new_image(void *mlx_ptr, int width, int height)
{
	void	*ret;

	ret = mlx_new_image(mlx_ptr, width, height);
	if (!ret)
		xperror(EM_MLX);
	return (ret);
}
