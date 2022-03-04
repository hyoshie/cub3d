/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:15:38 by hyoshie           #+#    #+#             */
/*   Updated: 2021/09/06 17:15:38 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_cp;
	t_list	*tmp;

	if (!lst || !(*lst))
		return ;
	lst_cp = *lst;
	while (lst_cp != NULL)
	{
		tmp = lst_cp->next;
		ft_lstdelone(lst_cp, del);
		lst_cp = tmp;
	}
	*lst = NULL;
}
