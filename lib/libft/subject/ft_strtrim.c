/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:17:42 by hyoshie           #+#    #+#             */
/*   Updated: 2021/09/06 17:17:42 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char const c, char const *list)
{
	while (*list)
	{
		if (*list == c)
			return (1);
		list++;
	}
	return (0);
}

static size_t	get_len_trimmed(char const *str, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	size_t	len_trimmed;

	start = 0;
	end = 0;
	len = ft_strlen(str);
	while (check_set(*(str + start), set))
		start++;
	str = str + len - 1;
	while (check_set(*(str - end), set))
		end++;
	len_trimmed = len - start - end;
	return (len_trimmed);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	idx;
	size_t	len_trimmed;

	if (!s1 || !set)
		return (NULL);
	idx = 0;
	len_trimmed = get_len_trimmed(s1, set);
	while (check_set(s1[idx], set))
		idx++;
	return (ft_substr(s1, idx, len_trimmed));
}
