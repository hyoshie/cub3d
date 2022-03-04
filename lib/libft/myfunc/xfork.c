/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:02:32 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/10 17:18:49 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

//use kill in xfork??
pid_t	xfork(void)
{
	pid_t	ret;

	ret = fork();
	if (ret < 0)
		xperror("fork");
	return (ret);
}
