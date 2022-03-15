/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:40:55 by yshimazu          #+#    #+#             */
/*   Updated: 2022/03/15 10:57:24 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

char	**clst_to_array(t_clst *buf, size_t height)
{
	t_clst	*t_buf;
	size_t	i;
	char	**map;

	t_buf = buf->next;
	map = (char **)malloc(sizeof(char *) * (height + 1));
	if (!map)
		xperror("malloc");
	i = 0;
	while (t_buf != buf)
	{
		map[i] = ft_strdup(t_buf->content);
		t_buf = t_buf->next;
		i++;
	}
	map[i] = NULL;
	clst_clear(buf);
	return (map);
}
