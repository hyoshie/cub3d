/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:17:39 by hyoshie           #+#    #+#             */
/*   Updated: 2021/09/06 17:17:39 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*last;
	char	c_char;

	last = (char *)str;
	c_char = (char)c;
	while (*last)
		last++;
	while (last != (char *)str)
	{
		if (*last == c_char)
			return (last);
		last--;
	}
	if (*last == c_char)
		return (last);
	return (NULL);
}
