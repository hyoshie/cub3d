/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:17:09 by hyoshie           #+#    #+#             */
/*   Updated: 2021/09/06 17:17:09 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	idx;
	size_t	len;

	idx = 0;
	len = ft_strlen(src);
	if (size == 0)
		return (len);
	while (src[idx] && idx < size - 1)
	{
		dst[idx] = src[idx];
		idx++;
	}
	dst[idx] = '\0';
	return (len);
}
