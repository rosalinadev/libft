/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:46:03 by event             #+#    #+#             */
/*   Updated: 2023/10/18 14:04:10 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	while (size > 0 && dst[j])
		j++;
	i = 0;
	if (j < size)
	{
		while (src[i] && i < size - j - 1)
		{
			dst[j + i] = src[i];
			i++;
		}
		dst[j + i] = '\0';
	}
	else
		j = size;
	while (src[i])
		i++;
	return (j + i);
}
