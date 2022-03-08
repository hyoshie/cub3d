/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 09:09:39 by hyoshie           #+#    #+#             */
/*   Updated: 2021/09/23 09:09:39 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

// current gnl
# include "../mylibft.h"
# define SUCCESS 1
# define END_OF_FILE 0
# define ERROR -1

typedef struct s_gnl
{
	int				fd;
	char			*memo;
	struct s_gnl	*next;
}				t_gnl;

t_gnl	*ft_gnlnew(int fd, char *c);
char	*ft_strndup(const char *src, size_t n);
char	*gnl(int fd);

// get_next_line_before
# define BUFFER_SIZE 1024 

size_t	gnl_strlen(const char *str);
char	*gnl_strdup(const char *s1);
char	*gnl_strjoin(char const *s1, char const *s2);
char	*gnl_strchr(const char *str, int c);
void	*free_set(char **ptr1, char *ptr2);
int		get_next_line(int fd, char **line);

#endif
