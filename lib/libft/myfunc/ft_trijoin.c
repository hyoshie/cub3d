/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trijoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:02:14 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/10 17:18:46 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

char	*ft_trijoin(char const *s1, char const *s2, char const *s3)
{
	return (ft_strjoin(s1, ft_strjoin(s2, s3)));
}
