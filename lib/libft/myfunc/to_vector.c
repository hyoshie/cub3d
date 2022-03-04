/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:08:02 by hyoshie           #+#    #+#             */
/*   Updated: 2021/12/14 09:44:00 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myfunc.h"

static int	make_firstnode(char **str, t_list **lst, int fd);
static void	*clear_set(t_list **lst, char *str);
static char	**set_strings_from_list(t_list *head);

char	**to_vector(int fd)
{
	char	*str;
	int		gnlflag;
	t_list	*tmp;
	t_list	*head;

	if (make_firstnode(&str, &head, fd))
		return (NULL);
	tmp = head;
	while (1)
	{
		gnlflag = get_next_line(fd, &str);
		if (gnlflag == 0)
			break ;
		if (gnlflag == -1)
			return (clear_set(&head, NULL));
		tmp = ft_lstnew(str);
		if (!tmp)
			return (clear_set(&head, str));
		ft_lstadd_back(&head, tmp);
	}
	return (set_strings_from_list(head));
}

static int	make_firstnode(char **str, t_list **lst, int fd)
{
	int	gnlflag;

	gnlflag = get_next_line(fd, str);
	if (gnlflag == -1)
		return (1);
	*lst = ft_lstnew(*str);
	if (!*lst)
	{
		free(*str);
		return (1);
	}
	return (0);
}

static void	*clear_set(t_list **lst, char *str)
{
	ft_lstclear(lst, free);
	if (str)
		free(str);
	return (NULL);
}

static char	**set_strings_from_list(t_list *head)
{
	char	**ret;
	size_t	lstsize;
	size_t	idx;
	t_list	*tmp;

	lstsize = ft_lstsize(head);
	ret = (char **)malloc(sizeof(char *) * (lstsize + 1));
	if (!ret)
		return (clear_set(&head, NULL));
	idx = 0;
	tmp = head;
	while (idx < lstsize)
	{
		ret[idx] = tmp->content;
		idx++;
		tmp = tmp->next;
	}
	ret[idx] = NULL;
	ft_lstclear(&head, NULL);
	return (ret);
}
