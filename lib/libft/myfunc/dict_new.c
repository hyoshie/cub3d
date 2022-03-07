/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:01:27 by yshimazu          #+#    #+#             */
/*   Updated: 2022/03/07 16:38:19 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

t_dict	*dict_new(char *key, char *value)
{
	t_dict	*elem;

	elem = (t_dict *)malloc(sizeof(t_dict));
	if (!elem)
		return (NULL);
	elem->key = key;
	elem->value = value;
	elem->prev = elem;
	elem->next = elem;
	return (elem);
}
