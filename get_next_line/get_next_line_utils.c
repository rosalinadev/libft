/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:09:59 by rvandepu          #+#    #+#             */
/*   Updated: 2023/12/13 10:53:38 by remty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
