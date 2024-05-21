/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 08:12:34 by rvandepu          #+#    #+#             */
/*   Updated: 2024/05/22 10:08:49 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <limits.h>

int	ft_min(unsigned int n, ...)
{
	va_list	args;
	int		min;
	int		i;

	if (n-- < 1)
		return (INT_MAX);
	va_start(args, n);
	min = va_arg(args, int);
	while (n--)
	{
		i = va_arg(args, int);
		if (i < min)
			min = i;
	}
	va_end(args);
	return (min);
}

int	ft_max(unsigned int n, ...)
{
	va_list	args;
	int		max;
	int		i;

	if (n-- < 1)
		return (INT_MIN);
	va_start(args, n);
	max = va_arg(args, int);
	while (n--)
	{
		i = va_arg(args, int);
		if (i > max)
			max = i;
	}
	va_end(args);
	return (max);
}
