/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtrijoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:02:14 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/22 00:41:55 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

char	*ft_xtrijoin(char const *s1, char const *s2, char const *s3)
{
	char	*tmp;
	char	*ret;

	tmp = ft_xstrjoin(s1, s2);
	ret = ft_xstrjoin(tmp, s3);
	free(tmp);
	return (ret);
}
