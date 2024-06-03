/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:09:59 by rvandepu          #+#    #+#             */
/*   Updated: 2024/06/03 18:48:47 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_buf	**gnl_get_mem(void)
{
	static t_buf	*mem[FD_MAX] = {NULL};

	return (mem);
}

void	free_gnl(void)
{
	t_buf	**mem;
	int		i;

	mem = gnl_get_mem();
	i = 0;
	while (i < FD_MAX)
		ft_memclear(&mem[i++]);
}

bool	ft_memclear(t_buf **mem)
{
	t_buf	*next;

	while (*mem)
	{
		next = (*mem)->next;
		free(*mem);
		*mem = next;
	}
	return (true);
}
