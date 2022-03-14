/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:25:29 by yshimazu          #+#    #+#             */
/*   Updated: 2022/03/14 22:02:20 by yshimazu         ###   ########.fr       */
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
		ft_putstr_fd(EM_ARG, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		exit (EXIT_SUCCESS);
	}
}
