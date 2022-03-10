/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myfunc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:18:05 by hyoshie           #+#    #+#             */
/*   Updated: 2022/01/05 20:34:52 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYFUNC_H
# define MYFUNC_H

# include <stdio.h>
# include <stdbool.h>
# include <sys/wait.h>
# include "../subject/libft.h"
# include "../gnl/get_next_line.h"
# include "color.h"
# include "dict.h"
# include "clst.h"

void	free_vector(char **vector);
int		ft_isspace(int c);
size_t	ft_lstsize_sizet(t_list *lst);
char	*ft_strajoin(char **str, char *connector);
size_t	ft_strclen(const char *str, int c);
size_t	ft_strclen_array(const char *str, char *sep);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strjoin3(const char *s1, const char *s2, const char *s3);
char	*ft_strndup(const char *s1, size_t n);
char	*ft_trijoin(char const *s1, char const *s2, char const *s3);
char	*ft_ulongtoa_base(unsigned long nbr, char *base);
int		ft_v_strchr(const char *str, int c);
void	*ft_xcalloc(size_t nmemb, size_t size);
char	*ft_xitoa(int n);
t_list	*ft_xlstnew(void *content);
char	**ft_xsplit(char const *s, char c);
char	*ft_strajoin(char **str, char *connector);
char	*ft_xstrdup(const char *s1);
char	*ft_xstrjoin(char const *s1, char const *s2);
char	*ft_strjoin3(const char *s1, const char *s2, const char *s3);
char	*ft_xstrmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_xstrndup(const char *s1, size_t n);
char	*ft_xsubstr(char const *s, unsigned int start, size_t len);
char	*ft_xtrijoin(char const *s1, char const *s2, char const *s3);
char	*ft_xulongtoa_base(unsigned long nbr, char *base);
void	multi_free(char *str1, char *str2, char *str3, char *str4);
char	**to_vector(int fd);
void	*xmalloc(size_t size);
void	xperror(char *s);

#endif
