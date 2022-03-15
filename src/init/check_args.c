/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:25:29 by yshimazu          #+#    #+#             */
/*   Updated: 2022/03/15 11:20:04 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

static int	check_extension(char *filename)
{
	char	*dot_ptr;

	dot_ptr = ft_strrchr(filename, '.');
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
		ft_putendl_fd(EM_ARG, STDERR_FILENO);
		exit (EXIT_SUCCESS);
	}
}
