/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:18:53 by rvandepu          #+#    #+#             */
/*   Updated: 2023/10/19 12:13:39 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*r;

	i = ft_strlen(s);
	if (start < i)
		i = start;
	else
		start = i;
	while (s[i++] && len--)
		;
	r = malloc(i - start);
	if (r == NULL)
		return (r);
	r[--i - start] = '\0';
	while (i-- > start)
		r[i - start] = s[i];
	return (r);
}
