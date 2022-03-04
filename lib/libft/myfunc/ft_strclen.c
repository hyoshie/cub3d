/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:16:53 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/10 11:28:39 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

size_t	ft_strclen(const char *str, int c)
{
	size_t	cnt;

	cnt = 0;
	while (*str && *str != c)
	{
		cnt++;
		str++;
	}
	return (cnt);
}

size_t	ft_strclen_array(const char *str, char *sep)
{
	size_t	cnt;

	cnt = 0;
	while (*str && ft_strchr(sep, *str) == NULL)
	{
		cnt++;
		str++;
	}
	return (cnt);
}
