/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:31:58 by rvandepu          #+#    #+#             */
/*   Updated: 2025/04/08 17:09:54 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	run_spec(unsigned char c, t_flags *flags, va_list args)
{
	static int (*const	spec[])(t_flags *flags, va_list args) = {\
		['d'] = ft_spec_dec, \
		['i'] = ft_spec_dec, \
		['u'] = ft_spec_uns, \
		['o'] = ft_spec_oct, \
		['x'] = ft_spec_hex, \
		['X'] = ft_spec_hex_upper, \
		['c'] = ft_spec_char, \
		['s'] = ft_spec_string, \
		['p'] = ft_spec_ptr, \
		['%'] = ft_spec_percent, \
	};

	return (spec[c](flags, args));
}

static int	ft_printf_core(int fd, const char *format, va_list args)
{
	int		next;
	t_flags	flags;

	flags = (t_flags){.fd = fd};
	next = ft_next_spec(format);
	if (next)
		return (ft_printstr(&flags, format, next)
			+ ft_printf_core(fd, format + next, args));
	next = ft_parse_spec(format, args, &flags);
	if (next)
		return (run_spec(flags.spec, &flags, args)
			+ ft_printf_core(fd, format + next, args));
	return (0);
}

int	ft_vfprintf(FILE *stream, const char *format, va_list args)
{
	int	fd;

	if (stream == stdout)
		fd = STDOUT_FILENO;
	else if (stream == stderr)
		fd = STDERR_FILENO;
	else
		return (ft_printf_core(STDOUT_FILENO,
				"ft_printf: arbitrary streams are unsupported\n", args));
	return (ft_printf_core(fd, format, args));
}
