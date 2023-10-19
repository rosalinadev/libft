/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:58:38 by rvandepu          #+#    #+#             */
/*   Updated: 2023/10/18 21:13:37 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *) big);
	i = 0;
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			j = 1;
			while (big[i + j] && big[i + j] == little[j] && i + j < len)
				j++;
			if (little[j] == '\0')
				return ((char *) big + i);
		}
		i++;
	}
	return (0);
}
