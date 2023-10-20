/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:40:52 by rvandepu          #+#    #+#             */
/*   Updated: 2023/10/20 15:53:34 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_itoa(int n)
{
	char	b[11];
	char	*s;
	int		i;
	int		j;

	ft_bzero(b, 11);
	if (n < 0)
		b[0] = '-';
	i = 10;
	while (n != 0)
	{
		b[i--] = '0' + n % 10 * ((n > 0) - (n < 0));
		n /= 10;
	}
	s = malloc(10 - i + 1 + (b[0] == '-') + (i == 10 && (b[10] = '0')));
	if (s == NULL)
		return (s);
	i = 0;
	j = 0;
	while (i < 11)
		if (b[i++])
			s[j++] = b[i - 1];
	s[j] = '\0';
	return (s);
}
