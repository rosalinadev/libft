/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:16:27 by rvandepu          #+#    #+#             */
/*   Updated: 2023/10/18 21:38:06 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int		s;
	long	n;

	while (*nptr == ' ' || ('\t' <= *nptr && *nptr <= '\r'))
		nptr++;
	s = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			s = -s;
		nptr++;
	}
	n = 0;
	while ('0' <= *nptr && *nptr <= '9')
	{
		n *= 10;
		n += *nptr - '0';
		nptr++;
	}
	return ((int)(s * n));
}
