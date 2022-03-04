/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:01:38 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/10 17:20:39 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

size_t	dict_size(t_dict *head)
{
	size_t	size;
	t_dict	*p;

	if (!head)
		return (0);
	size = 0;
	p = head->next;
	while (p != head)
	{
		p = p->next;
		size++;
	}
	return (size);
}
