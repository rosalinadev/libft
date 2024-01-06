/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:09:29 by rvandepu          #+#    #+#             */
/*   Updated: 2023/12/13 10:54:22 by remty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static bool	ft_read_to_mem(t_buf **mem, int fd)
{
	t_buf	*buf;

	buf = malloc(sizeof(t_buf));
	if (buf == NULL)
		return (!ft_memclear(mem));
	buf->next = NULL;
	buf->read = read(fd, buf->content, BUFFER_SIZE);
	if (buf->read < 0 || (*mem == NULL && buf->read == 0))
	{
		free(buf);
		return (!ft_memclear(mem));
	}
	while (*mem)
		mem = &(*mem)->next;
	(*mem) = buf;
	return (true);
}

static long	ft_mem_has_line(t_buf *mem)
{
	long	i;
	long	n;

	n = 0;
	while (mem)
	{
		if (!mem->read)
			return (n);
		i = -1;
		while (++i < mem->read)
			if (mem->content[i] == '\n')
				return (n + i + 1);
		n += mem->read;
		mem = mem->next;
	}
	return (0);
}

static bool	ft_get_line(t_buf **mem, char **line)
{
	long	l;
	long	c;

	l = ft_mem_has_line(*mem);
	c = l;
	*line = malloc(l + 1);
	if (*line == NULL)
		return (!ft_memclear(mem));
	while (*mem)
	{
		ft_memcpy(*line + l - c, (*mem)->content,
			(*mem)->read * ((*mem)->read <= c) + c * ((*mem)->read > c));
		c -= (*mem)->read;
		mem = &(*mem)->next;
	}
	(*line)[l] = '\0';
	return (true);
}

static bool	ft_mem_next(t_buf **mem)
{
	t_buf	*new;
	t_buf	*buf;
	long	left;

	buf = *mem;
	left = ft_mem_has_line(buf);
	while (buf && buf->read <= left)
	{
		left -= buf->read;
		buf = buf->next;
	}
	if (!buf)
		return (ft_memclear(mem));
	new = malloc(sizeof(t_buf));
	if (new == NULL)
		return (!ft_memclear(mem));
	new->next = NULL;
	new->read = buf->read - ft_mem_has_line(buf);
	ft_memcpy(new->content, buf->content + ft_mem_has_line(buf), new->read);
	ft_memclear(mem);
	*mem = new;
	return (true);
}

char	*get_next_line(int fd)
{
	static t_buf	*mem[FD_MAX] = {NULL};
	char			*line;

	if (fd < 0)
		return (NULL);
	while (!ft_mem_has_line(mem[fd]))
		if (!ft_read_to_mem(&mem[fd], fd))
			return (NULL);
	if (!ft_get_line(&mem[fd], &line))
		return (NULL);
	if (!ft_mem_next(&mem[fd]))
	{
		free(line);
		return (NULL);
	}
	return (line);
}
