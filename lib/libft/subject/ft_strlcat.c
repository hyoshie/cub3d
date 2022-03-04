/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:17:04 by hyoshie           #+#    #+#             */
/*   Updated: 2021/09/06 17:17:04 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	idx;
	size_t	len_dest;
	size_t	len_src;

	idx = 0;
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	while (*dest)
		dest++;
	while (src[idx] && len_dest + idx < size - 1)
		*dest++ = src[idx++];
	*dest = '\0';
	if (len_dest < size)
		return (len_dest + len_src);
	else
		return (size + len_src);
}
