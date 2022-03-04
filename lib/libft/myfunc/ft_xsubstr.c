/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xsubstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:17:46 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/14 00:44:15 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

char	*ft_xsubstr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s == NULL || (size_t)start > s_len)
		return (ft_strdup(""));
	if (len > s_len - (size_t)start)
		len = s_len - (size_t)start;
	substr = (char *)xmalloc(sizeof(char) * (len + 1));
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
