/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_substr_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:08:21 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/25 22:17:24 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

char	*dict_substr_value(char *expression, char *connector)
{
	char	*value;
	char	*cptr;

	if (!expression || !connector)
		return (NULL);
	cptr = ft_strnstr(expression, connector, ft_strlen(expression));
	if (!cptr)
		return (NULL);
	value = ft_xstrdup(cptr + ft_strlen(connector));
	return (value);
}
