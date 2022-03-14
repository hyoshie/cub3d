/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:49:24 by yshimazu          #+#    #+#             */
/*   Updated: 2022/03/14 14:50:17 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

size_t	dict_count(t_dict *dict)
{
	size_t	num;
	t_dict	*p;

	p = dict->next;
	num = 0;
	while (p != dict)
	{
		num++;
		p = p->next;
	}
	return (num);
}
