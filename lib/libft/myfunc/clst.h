/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:22:59 by hyoshie           #+#    #+#             */
/*   Updated: 2022/03/07 13:41:21 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLST_H
# define CLST_H

# include <stdbool.h>

typedef struct s_clst
{
	char			*content;
	struct s_clst	*prev;
	struct s_clst	*next;
}		t_clst;

void	clst_addback(t_clst *head, t_clst *new);
void	clst_addfront(t_clst *head, t_clst *new);
void	clst_clear(t_clst *head);
bool	clst_delone(t_clst *elem);
void	clst_insert(t_clst *lst, t_clst *new);
void	clst_link(t_clst *now, t_clst *next);
t_clst	*clst_new(char *content);
void	clst_del_content(t_clst *path_clst, char *del_content);
size_t	clst_count(t_clst *clst);
char	**clst_to_array(t_clst *buf, size_t height);

#endif
