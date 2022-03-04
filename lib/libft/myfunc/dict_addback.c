/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_addback.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:00:56 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/10 17:16:27 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

bool	dict_addback(t_dict *head, t_dict *new)
{
	if (!head || !new)
		return (false);
	new->next = head;
	new->prev = head->prev;
	head->prev->next = new;
	head->prev = new;
	return (true);
}
