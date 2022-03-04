/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 09:36:38 by hyoshie           #+#    #+#             */
/*   Updated: 2021/09/24 09:37:14 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

void	free_vector(char **vector)
{
	size_t	idx;

	idx = 0;
	if (!vector)
		return ;
	while (vector[idx])
	{
		free(vector[idx]);
		idx += 1;
	}
	free(vector);
}
