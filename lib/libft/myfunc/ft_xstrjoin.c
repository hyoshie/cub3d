/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:17:01 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/14 09:52:58 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

char	*ft_xstrjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 && !s2)
		return (ft_xstrdup(s1));
	if (!s1 && s2)
		return (ft_xstrdup(s2));
	if (!s1 && !s2)
		return (ft_xstrdup(""));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)xmalloc(sizeof(char) * (s1_len + s2_len + 1));
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcat(str, s2, s1_len + s2_len + 1);
	return (str);
}
