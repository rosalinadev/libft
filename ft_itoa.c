/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:40:52 by rvandepu          #+#    #+#             */
/*   Updated: 2024/10/15 04:34:21 by rvandepu         ###   ########.fr       */
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

void	ft_itoa_buf(int n, char b[12])
{
	int		i;
	int		j;

	ft_bzero(b, 12);
	if (n < 0)
		b[0] = '-';
	i = 10;
	while (n != 0)
	{
		b[i--] = '0' + n % 10 * ((n > 0) - (n < 0));
		n /= 10;
	}
	if (i == 10)
		b[10] = '0';
	i = 0;
	j = 0;
	while (i < 11)
		if (b[i++])
			b[j++] = b[i - 1];
	b[j] = '\0';
}
