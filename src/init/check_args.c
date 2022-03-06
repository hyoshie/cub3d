/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:25:29 by yshimazu          #+#    #+#             */
/*   Updated: 2022/03/06 15:25:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "minimap.h"

static int	check_extension(char *filename)
{
	char	*dot_ptr;

	dot_ptr = ft_strchr(filename, '.');
	if (dot_ptr == NULL)
		return (-1);
	else
	{
		if (ft_strncmp(dot_ptr, ".cub\0", 5))
			return (-1);
	}
	return (0);
}

void	check_args(int ac, char **av)
{
	if (ac != 2 || check_extension(av[1]) == -1)
	{
		ft_putstr_fd("Error\nUsage: ./cub3d xxx.cub\n", 2);
		exit (EXIT_SUCCESS);
	}
}
