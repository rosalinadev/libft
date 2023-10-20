/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:19:24 by rvandepu          #+#    #+#             */
/*   Updated: 2023/10/20 16:30:54 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	b[12];
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
	ft_putstr_fd(b, fd);
}
