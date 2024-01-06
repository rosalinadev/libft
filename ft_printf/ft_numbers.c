/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:25:54 by rvandepu          #+#    #+#             */
/*   Updated: 2023/12/20 14:05:54 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_spec_dec(t_flags *flags, va_list args)
{
	return (ft_putnbr_base(va_arg(args, int), 10, flags));
}

int	ft_spec_uns(t_flags *flags, va_list args)
{
	return (ft_putnbr_base(va_arg(args, unsigned int), 10, flags));
}

int	ft_spec_oct(t_flags *flags, va_list args)
{
	return (ft_putnbr_base(va_arg(args, unsigned int), 8, flags));
}

int	ft_spec_hex(t_flags *flags, va_list args)
{
	return (ft_putnbr_base(va_arg(args, unsigned int), 16, flags));
}

int	ft_spec_hex_upper(t_flags *flags, va_list args)
{
	flags->upper = true;
	return (ft_spec_hex(flags, args));
}
