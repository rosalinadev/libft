/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remty <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:11:16 by remty             #+#    #+#             */
/*   Updated: 2023/10/18 22:15:37 by remty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*d;
	int		i;

	i = ft_strlen(s);
	d = malloc(i + 1);
	if (d == NULL)
		return (d);
	d[i] = '\0';
	while (i--)
		d[i] = s[i];
	return (d);
}
