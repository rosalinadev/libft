/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:34:24 by rvandepu          #+#    #+#             */
/*   Updated: 2023/10/18 16:05:19 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest > src)
		while (n--)
			((char *) dest)[n] = ((char *) src)[n];
	else if (dest < src)
	{
		i = -1;
		while (++i < n)
			((char *) dest)[i] = ((char *) src)[i];
	}
	return (dest);
}
