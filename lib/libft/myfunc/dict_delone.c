/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_delone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:01:15 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/10 17:18:44 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

bool	dict_delone(t_dict *elem)
{
	t_dict	*front;
	t_dict	*back;

	if (!elem || elem->next == elem)
		return (false);
	front = elem->next;
	back = elem->prev;
	back->next = front;
	front->prev = back;
	free(elem->key);
	free(elem->value);
	free(elem);
	return (true);
}
