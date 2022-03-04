/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlstnew_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:15:51 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/14 00:44:14 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

t_list	*ft_xlstnew(void *content)
{
	t_list	*p;

	p = (t_list *)xmalloc(sizeof(t_list));
	p->content = content;
	p->next = NULL;
	return (p);
}
