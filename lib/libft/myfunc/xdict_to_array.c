/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xdict_to_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:01:47 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/14 21:04:21 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

char	**xdict_to_array(t_dict *dict_head, char *connector)
{
	char	**array;
	t_dict	*p;
	size_t	i;
	size_t	size;

	size = dict_size(dict_head);
	p = dict_head->next;
	array = xmalloc(sizeof(char *) * (size + 1));
	i = -1;
	while (++i < size)
	{
		array[i] = ft_xtrijoin(p->key, connector, p->value);
		p = p->next;
	}
	array[i] = NULL;
	return (array);
}
