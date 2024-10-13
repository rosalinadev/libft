/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:12:11 by rvandepu          #+#    #+#             */
/*   Updated: 2024/10/13 04:02:37 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(int count, char **strs)
{
	char	*s;
	int		len;
	int		i;
	int		j;

	len = 0;
	i = 0;
	while ((count < 0 || i < count) && strs[i])
		len += ft_strlen(strs[i++]);
	count = i;
	s = malloc(len + 1);
	if (s == NULL)
		return (s);
	s[len] = '\0';
	len = 0;
	i = 0;
	while (i < count)
	{
		j = 0;
		while (strs[i][j])
			s[len++] = strs[i][j++];
		i++;
	}
	return (s);
}

static bool	joinv(int count, char **ret, va_list *arg, size_t len)
{
	char	*s;

	if (count != 0)
		s = va_arg(*arg, char *);
	if (count == 0 || s == NULL)
	{
		*ret = malloc(len + 1);
		if (*ret == NULL)
			return (false);
		(*ret)[len] = '\0';
		return (true);
	}
	if (!joinv((count * (count > 0)) - 1, ret, arg, len + ft_strlen(s)))
		return (false);
	while (*s)
		(*ret)[len++] = *s++;
	return (true);
}

char	*ft_strjoinv(int count, ...)
{
	char	*s;
	va_list	arg;

	va_start(arg, count);
	if (!joinv(count, &s, &arg, 0))
		return (va_end(arg), NULL);
	return (va_end(arg), s);
}
