/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_search_item.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:37:36 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/18 01:45:27 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

t_dict	*dict_search_item(char *key, t_dict *dict)
{
	t_dict	*ptr;

	if (key == NULL || dict == NULL)
		return (NULL);
	ptr = dict->next;
	while (ptr != dict)
	{
		if (ft_strcmp(key, ptr->key) == 0)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}
