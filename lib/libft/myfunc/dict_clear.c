/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:01:06 by yshimazu          #+#    #+#             */
/*   Updated: 2022/03/08 00:01:31 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

void	dict_clear(t_dict *head)
{
	t_dict	*p;

	p = head->next;
	while (p != head)
	{
		p = p->next;
		free(p->prev->key);
		free(p->prev->value);
		free (p->prev);
	}
	free (head);
}
