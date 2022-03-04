/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:16:55 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/14 00:44:14 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

char	*ft_xstrdup(const char *s1)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s1);
	str = xmalloc(sizeof(char) * (len + 1));
	ft_strlcpy(str, s1, len + 1);
	return (str);
}
