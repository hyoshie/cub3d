/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_xstore_item.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 13:33:23 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/25 22:15:53 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

t_dict	*dict_xstore_item(char *expression, char *connector)
{
	t_dict	*item;
	char	*key;
	char	*value;
	char	*cptr;

	if (!expression || !connector)
		return (NULL);
	cptr = ft_strnstr(expression, connector, ft_strlen(expression));
	if (!cptr)
		return (NULL);
	key = dict_substr_key(expression, connector);
	value = dict_substr_value(expression, connector);
	item = xdict_new(key, value);
	return (item);
}
