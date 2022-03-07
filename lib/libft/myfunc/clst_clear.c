/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 00:57:44 by yshimazu          #+#    #+#             */
/*   Updated: 2022/03/07 17:57:59 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

void	clst_clear(t_clst *head)
{
	t_clst	*p;

	p = head->next;
	while (p != head)
	{
		p = p->next;
		free(p->prev->content);
		free(p->prev);
	}
	free (head);
}
