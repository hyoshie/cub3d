/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstrmapi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:17:15 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/14 00:44:15 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

char	*ft_xstrmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	idx;

	if (!s || !f)
		return (NULL);
	str = (char *)xmalloc(sizeof(char) * (ft_strlen(s) + 1));
	idx = 0;
	while (s[idx])
	{
		str[idx] = f((unsigned int)idx, s[idx]);
		idx++;
	}
	str[idx] = '\0';
	return (str);
}
