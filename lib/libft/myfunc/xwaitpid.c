/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xwaitpid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:58:05 by yshimazu          #+#    #+#             */
/*   Updated: 2021/12/18 01:45:47 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

void	xwaitpid(pid_t pid, int *status, int options)
{
	int	ret;

	ret = waitpid(pid, status, options);
	if (ret == -1)
		xperror("waitpid");
}
