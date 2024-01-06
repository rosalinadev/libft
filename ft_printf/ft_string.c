/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:39:54 by rvandepu          #+#    #+#             */
/*   Updated: 2024/01/05 15:30:46 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(t_flags *flags, const char *str, int len)
{
	int		ret;
	char	c;
	int		i;

	if (len < flags->width)
		ret = flags->width;
	else
		ret = len;
	while (!flags->leftjust && len < flags->width--)
		write(1, &" 0" + flags->zero, 1);
	i = 0;
	while (flags->upper && i < len)
	{
		c = ft_toupper(str[i++]);
		write(1, &c, 1);
	}
	if (!flags->upper)
		write(1, str, len);
	while (len < flags->width--)
		write(1, &" ", 1);
	return (ret);
}

int	ft_spec_char(t_flags *flags, va_list args)
{
	char	c;

	c = va_arg(args, int);
	return (ft_printstr(flags, &c, 1));
}

int	ft_spec_string(t_flags *flags, va_list args)
{
	char	*str;
	int		len;

	str = va_arg(args, char *);
	if (str == NULL && (flags->precision >= 6 || flags->precision == -1))
		return (ft_printstr(flags, "(null)", 6));
	else if (str == NULL)
		return (ft_printstr(flags, NULL, 0));
	len = 0;
	if (flags->precision >= 0)
		while (str[len] && len < flags->precision)
			len++;
	else
		len = ft_strlen(str);
	return (ft_printstr(flags, str, len));
}

int	ft_spec_percent(t_flags *flags, va_list args)
{
	(void) args;
	return (ft_printstr(flags, &flags->spec, 1));
}
