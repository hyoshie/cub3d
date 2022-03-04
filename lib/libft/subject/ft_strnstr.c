/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:17:19 by hyoshie           #+#    #+#             */
/*   Updated: 2021/09/06 17:17:19 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	idx;
	size_t	little_len;

	idx = 0;
	little_len = ft_strlen(little);
	if (little[0] == '\0')
		return ((char *)big);
	while (big[idx] != '\0' && idx + little_len <= len)
	{
		if (ft_strncmp(big + idx, little, little_len) == 0)
			return ((char *)big + idx);
		idx++;
	}
	return (NULL);
}
