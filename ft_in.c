/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 06:23:32 by rvandepu          #+#    #+#             */
/*   Updated: 2024/10/13 06:24:48 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	ft_in(char c, char *set)
{
	while (*set)
		if (c == *set++)
			return (true);
	return (false);
}
