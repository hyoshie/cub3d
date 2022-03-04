/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_before.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 09:06:03 by hyoshie           #+#    #+#             */
/*   Updated: 2021/09/23 09:06:03 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static ssize_t	set_return_ssize_t(ssize_t *cnt, ssize_t read);
static char		*set_return_str(char **str1, char *str2);
static int		reset_for_error(char **line, char **left, char *buf);
static int		check_strs(ssize_t cnt, char **line, char **left, char *buf);

int	get_next_line(int fd, char **line)
{
	static char	*left;
	char		*buf;
	char		*nlptr;
	ssize_t		cnt;

	*line = left;
	left = NULL;
	buf = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buf)
		return (reset_for_error(line, &left, buf));
	while (set_return_ssize_t(&cnt, read(fd, buf, BUFFER_SIZE)) >= 0)
	{
		buf[cnt] = '\0';
		free_set(line, gnl_strjoin(*line, buf));
		if (*line && set_return_str(&nlptr, gnl_strchr(*line, '\n')))
		{
			*nlptr = '\0';
			left = gnl_strdup(nlptr + 1);
			free_set(line, gnl_strdup(*line));
			return (check_strs(cnt, line, &left, buf));
		}
		if (!*line || cnt == 0)
			return (check_strs(cnt, line, &left, buf));
	}
	return (reset_for_error(line, &left, buf));
}

static ssize_t	set_return_ssize_t(ssize_t *cnt, ssize_t read)
{
	*cnt = read;
	return (*cnt);
}

static char	*set_return_str(char **str1, char *str2)
{
	*str1 = str2;
	return (*str1);
}

static int	reset_for_error(char **line, char **left, char *buf)
{
	free_set(line, NULL);
	free_set(left, NULL);
	free_set(&buf, NULL);
	return (-1);
}

static int	check_strs(ssize_t cnt, char **line, char **left, char *buf)
{
	int	ret;

	free_set(&buf, NULL);
	ret = cnt;
	if (!*line)
		ret = reset_for_error(line, left, buf);
	else if (cnt > 0 || *left || gnl_strlen(*line) > 0)
		ret = 1;
	else
		free(*line);
	return (ret);
}
