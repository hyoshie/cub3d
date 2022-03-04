/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:14:52 by hyoshie           #+#    #+#             */
/*   Updated: 2021/09/06 17:14:52 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	get_int(char c)
{
	return ((long)(c - '0'));
}

static long	change_atoi(const char *nptr, int sign)
{
	long	nbr;
	long	mod;
	long	div;
	long	tmp;

	nbr = 0;
	mod = LONG_MAX % 10;
	div = LONG_MAX / 10;
	tmp = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		tmp = get_int(*nptr);
		if ((nbr > div || ((nbr == div && tmp > mod))) && sign == 1)
			return ((int)LONG_MAX);
		if ((nbr > div || (nbr == div && tmp > mod + 1)) && sign == -1)
			return ((int)LONG_MIN);
		nbr = nbr * 10 + tmp;
		nptr++;
	}
	return (nbr);
}

int	ft_atoi(const char *nptr)
{
	long	l_nbr;
	int		nbr;
	int		sign;

	sign = 1;
	while (*nptr == ' ' || *nptr == '\f' || *nptr == '\n'
		|| *nptr == '\r' || *nptr == '\t' || *nptr == '\v')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	l_nbr = change_atoi(nptr, sign);
	nbr = (int)l_nbr;
	return (sign * nbr);
}
