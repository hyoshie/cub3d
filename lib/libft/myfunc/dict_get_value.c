/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_get_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:06:58 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/16 13:16:20 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

char	*dict_get_value(const char *key, t_dict *head)
{
	t_dict	*t_env;

	t_env = head->next;
	while (t_env != head)
	{
		if (ft_strcmp(t_env->key, key) == 0)
			return (t_env->value);
		t_env = t_env->next;
	}
	return (NULL);
}
