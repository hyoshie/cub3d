/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:16:37 by hyoshie           #+#    #+#             */
/*   Updated: 2021/09/06 17:16:37 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	l_nbr;

	l_nbr = (long)n;
	if (l_nbr < 0)
	{
		l_nbr = l_nbr * (-1);
		write(fd, "-", 1);
	}
	if (l_nbr >= 10)
	{
		ft_putnbr_fd(l_nbr / 10, fd);
		ft_putchar_fd('0' + l_nbr % 10, fd);
	}
	else
		ft_putchar_fd('0' + l_nbr, fd);
}
