/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:16:22 by hyoshie           #+#    #+#             */
/*   Updated: 2021/09/06 17:16:22 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*to;
	unsigned char	*from;

	to = (unsigned char *)dest;
	from = (unsigned char *)src;
	if (dest == src)
		return (dest);
	while (n--)
		*to++ = *from++;
	return (dest);
}
