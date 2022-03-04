/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstrjoin3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:17:06 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/14 10:00:01 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

char	*ft_xstrjoin3(const char *s1, const char *s2, const char *s3)
{
	char	*ret_m;
	char	*tmp_m;

	if (!s1 || !s2 || !s3)
		return (NULL);
	tmp_m = ft_xstrjoin(s1, s2);
	ret_m = ft_xstrjoin(tmp_m, s3);
	free(tmp_m);
	return (ret_m);
}
