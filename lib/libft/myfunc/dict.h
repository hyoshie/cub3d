/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:22:59 by hyoshie           #+#    #+#             */
/*   Updated: 2022/03/14 14:50:32 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

# include <stdbool.h>

typedef struct s_dict
{
	struct s_dict	*prev;
	char			*key;
	char			*value;
	struct s_dict	*next;
}				t_dict;

bool	dict_addback(t_dict *head, t_dict *new);
void	dict_clear(t_dict *head);
bool	dict_delone(t_dict *elem);
size_t	dict_count(t_dict *dict);
t_dict	*dict_new(char *key, char *value);
size_t	dict_size(t_dict *head);
char	**dict_to_array(t_dict *dict_head, char *connector);
t_dict	*xdict_new(char *key, char *value);
char	**xdict_to_array(t_dict *dict_head, char *connector);
char	*dict_get_value(const char *key, t_dict *head);
t_dict	*dict_search_item(char *key, t_dict *dict);
void	dict_update_value(char *key, char *new_value, t_dict *dict);
t_dict	*dict_store_item(char *line, char connector);
t_dict	*dict_xstore_item(char *line, char *connector);
char	*dict_substr_key(char *line, char *connector);
char	*dict_substr_value(char *line, char *connector);

#endif
