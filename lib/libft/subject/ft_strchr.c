/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:16:50 by hyoshie           #+#    #+#             */
/*   Updated: 2021/09/06 17:16:50 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	c_char;

	c_char = (char)c;
	while (*str)
	{
		if (*str == c_char)
			return ((char *)str);
		str++;
	}
	if (c_char == '\0')
		return ((char *)str);
	return (NULL);
}
