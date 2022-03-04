/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 19:45:08 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/17 19:47:17 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

void	multi_free(char *str1, char *str2, char *str3, char *str4)
{
	free(str1);
	free(str2);
	free(str3);
	free(str4);
}
