/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 00:56:13 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/22 00:56:17 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

t_clst	*clst_new(char *content)
{
	t_clst	*elem;

	elem = (t_clst *)xmalloc(sizeof(t_clst));
	if (!elem)
		return (NULL);
	elem->content = content;
	elem->prev = elem;
	elem->next = elem;
	return (elem);
}
