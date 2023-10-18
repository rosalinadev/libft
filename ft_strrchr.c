/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:35:44 by rvandepu          #+#    #+#             */
/*   Updated: 2023/10/18 17:07:34 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	l;

	i = -1;
	l = -1;
	while (s[++i])
		if (s[i] == c % 256)
			l = i;
	if (l >= 0)
		return ((char *) s + l);
	else if (!(c % 256))
		return ((char *) s + i);
	return (NULL);
}
