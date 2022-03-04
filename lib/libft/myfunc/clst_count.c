/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 01:10:03 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/22 09:21:40 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

size_t	clst_count(t_clst *clst)
{
	size_t	num;
	t_clst	*p;

	p = clst->next;
	num = 0;
	while (p != clst)
	{
		num++;
		p = p->next;
	}
	return (num);
}
