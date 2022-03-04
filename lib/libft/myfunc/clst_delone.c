/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_delone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 00:56:59 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/22 00:57:02 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

bool	clst_delone(t_clst *elem)
{
	t_clst	*front;
	t_clst	*back;

	if (!elem || elem->next == elem)
		return (false);
	front = elem->next;
	back = elem->prev;
	back->next = front;
	front->prev = back;
	free(elem->content);
	free(elem);
	return (true);
}
