/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_del_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 01:11:00 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/22 09:20:52 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

void	clst_del_content(t_clst *path_clst, char *del_content)
{
	t_clst	*p;

	p = path_clst->next;
	while (p != path_clst)
	{
		if (ft_strcmp(p->content, del_content) == 0)
		{
			p = p->next;
			clst_delone(p->prev);
			continue ;
		}
		p = p->next;
	}
}
