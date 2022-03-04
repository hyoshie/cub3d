/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xdict_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:01:27 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/14 09:38:30 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

t_dict	*xdict_new(char *key, char *value)
{
	t_dict	*elem;

	elem = (t_dict *)xmalloc(sizeof(t_dict));
	elem->key = key;
	elem->value = value;
	elem->prev = elem;
	elem->next = elem;
	return (elem);
}
