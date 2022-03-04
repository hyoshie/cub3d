/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 09:06:07 by hyoshie           #+#    #+#             */
/*   Updated: 2021/09/23 09:06:07 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *str)
{
	size_t	cnt;

	cnt = 0;
	while (*str++)
		cnt++;
	return (cnt);
}

char	*gnl_strdup(const char *s1)
{
	char	*str;
	size_t	len;
	size_t	idx;

	len = gnl_strlen(s1);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	idx = 0;
	while (len--)
		str[idx++] = *s1++;
	str[idx] = '\0';
	return (str);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	idx;

	if (s1 &&!s2)
		return (gnl_strdup(s1));
	if (!s1 && s2)
		return (gnl_strdup(s2));
	if (!s1 && !s2)
		return (gnl_strdup(""));
	s1_len = gnl_strlen(s1);
	s2_len = gnl_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	idx = 0;
	while (s1_len--)
		str[idx++] = *s1++;
	while (s2_len--)
		str[idx++] = *s2++;
	str[idx] = '\0';
	return (str);
}

char	*gnl_strchr(const char *str, int c)
{
	char	c_char;

	if (!str)
		return (NULL);
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

void	*free_set(char **ptr1, char *ptr2)
{
	free(*ptr1);
	*ptr1 = ptr2;
	return (ptr2);
}
