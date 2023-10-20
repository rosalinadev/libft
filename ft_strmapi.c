/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:38:44 by rvandepu          #+#    #+#             */
/*   Updated: 2023/10/20 16:42:44 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*r;
	int		i;

	r = malloc(ft_strlen(s) + 1);
	if (r == NULL)
		return (r);
	i = -1;
	while (s[++i])
		r[i] = f(i, s[i]);
	r[i] = '\0';
	return (r);
}
