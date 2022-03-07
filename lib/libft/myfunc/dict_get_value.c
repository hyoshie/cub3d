/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_get_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:06:58 by hyoshie           #+#    #+#             */
/*   Updated: 2022/03/07 16:41:31 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

char	*dict_get_value(const char *key, t_dict *head)
{
	t_dict	*t_env;

	t_env = head->next;
	while (t_env != head)
	{
		if (!t_env->key)
		{
			t_env = t_env->next;
			continue ;
		}
		if (ft_strcmp(t_env->key, key) == 0)
			return (t_env->value);
		t_env = t_env->next;
	}
	return (NULL);
}
