/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:25:43 by rvandepu          #+#    #+#             */
/*   Updated: 2024/02/28 04:46:38 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdbool.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_flags
{
	int		fd;
	bool	leftjust;
	bool	sign;
	bool	space;
	bool	prefix;
	bool	zero;
	int		width;
	int		precision;
	bool	upper;
	char	spec;
}	t_flags;

// ft_print.c
int	ft_print(va_list args);

// ft_printf.c
int	ft_vfprintf(FILE *stream, const char *format, va_list args);
int	ft_vprintf(const char *format, va_list args);
int	ft_fprintf(FILE *stream, const char *format, ...);
int	ft_printf(const char *format, ...);

// ft_parser.c
int	ft_next_spec(const char *format);
int	ft_parse_spec(const char *format, va_list args, t_flags *flags);

// ft_string.c
int	ft_printstr(t_flags *flags, const char *str, int len);
int	ft_spec_char(t_flags *flags, va_list args);
int	ft_spec_string(t_flags *flags, va_list args);
int	ft_spec_percent(t_flags *flags, va_list args);

// ft_putnbr.c
int	ft_putnbr_base(long n, char base, t_flags *flags);
int	ft_spec_ptr(t_flags *flags, va_list args);

// ft_numbers.c
int	ft_spec_dec(t_flags *flags, va_list args);
int	ft_spec_uns(t_flags *flags, va_list args);
int	ft_spec_oct(t_flags *flags, va_list args);
int	ft_spec_hex(t_flags *flags, va_list args);
int	ft_spec_hex_upper(t_flags *flags, va_list args);

#endif
