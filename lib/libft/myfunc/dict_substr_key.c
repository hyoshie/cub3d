/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_substr_key.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 18:52:22 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/25 22:16:50 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

char	*dict_substr_key(char *expression, char *connector)
{
	char	*key;
	char	*cptr;

	if (!expression || !connector)
		return (NULL);
	cptr = ft_strnstr(expression, connector, ft_strlen(expression));
	if (!cptr)
		return (NULL);
	key = ft_xsubstr(expression, 0, cptr - expression);
	return (key);
}
