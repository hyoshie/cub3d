/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstrajoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:01:56 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/14 10:00:38 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

char	*ft_xstrajoin(char **str, char *connector)
{
	size_t	i;
	char	*joined_str;
	char	*tmp;

	joined_str = ft_xstrdup(str[0]);
	i = 1;
	while (str[i])
	{
		tmp = ft_xtrijoin(joined_str, connector, str[i]);
		free(joined_str);
		joined_str = tmp;
		i++;
	}
	return (joined_str);
}
