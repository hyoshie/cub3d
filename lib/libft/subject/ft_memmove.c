/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:16:25 by hyoshie           #+#    #+#             */
/*   Updated: 2021/09/06 17:16:25 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*to;
	unsigned char	*from;

	to = (unsigned char *)dest;
	from = (unsigned char *)src;
	if (to > from && from + n > to)
	{
		to = to + n - 1;
		from = from + n - 1;
		while (n--)
			*to-- = *from--;
	}
	else
	{
		ft_memcpy(to, from, n);
	}
	return (dest);
}
