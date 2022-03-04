/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xulongtoa_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:17:56 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/14 09:42:34 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

static int	get_length(unsigned long nbr, unsigned long base_num)
{
	int	digit;

	digit = 1;
	while (nbr >= base_num)
	{
		nbr = nbr / base_num;
		digit++;
	}
	return (digit);
}

char	*ft_xulongtoa_base(unsigned long nbr, char *base)
{
	unsigned long	base_num;
	int				digit;
	char			*str;

	if (!base)
		return (NULL);
	base_num = (unsigned long)ft_strlen(base);
	digit = get_length(nbr, base_num);
	str = (char *)xmalloc(sizeof(char) * (digit + 1));
	str[digit] = '\0';
	if (nbr == 0)
		str[0] = '0';
	else
	{
		while (nbr)
		{
			digit--;
			str[digit] = base[nbr % base_num];
			nbr = nbr / base_num;
		}
	}
	return (str);
}
