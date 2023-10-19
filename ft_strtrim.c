/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:18:53 by rvandepu          #+#    #+#             */
/*   Updated: 2023/10/19 14:24:03 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static int	ft_in_set(char const c, char const *set)
{
	int	i;

	i = -1;
	while (set[++i])
		if (c == set[i])
			return (1);
	return (!c);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*r;

	i = 0;
	j = ft_strlen(s1);
	while (i < j && ft_in_set(s1[i], set))
		i++;
	while (j > i && ft_in_set(s1[j], set))
		j--;
	if (i == j && ft_in_set(s1[i], set))
		j--;
	r = malloc(++j - i + 1);
	if (r == NULL)
		return (r);
	r[j - i] = '\0';
	while (j-- > i)
		r[j - i] = s1[j];
	return (r);
}
