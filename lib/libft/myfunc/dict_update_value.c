/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_update_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 01:03:33 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/25 16:44:45 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

void	dict_update_value(char *key, char *new_value, t_dict *dict)
{
	t_dict	*item;

	item = dict_search_item(key, dict);
	if (!item)
		dict_addback(dict, xdict_new(key, new_value));
	else
	{
		free(key);
		if (new_value)
		{
			free(item->value);
			item->value = new_value;
		}
	}
}
