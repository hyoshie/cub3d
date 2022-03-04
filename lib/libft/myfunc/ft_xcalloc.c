/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xcalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:15:05 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/14 00:44:14 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

void	*ft_xcalloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = xmalloc(sizeof(unsigned char) * nmemb * size);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
