/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:17:36 by hyoshie           #+#    #+#             */
/*   Updated: 2021/11/28 14:50:11 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	idx;

	idx = 0;
	while (idx < n && s1[idx])
	{
		if (s1[idx] != s2[idx])
			break ;
		idx++;
	}
	if (idx == n)
		return (0);
	return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
}
