/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitwise.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 13:33:28 by rvandepu          #+#    #+#             */
/*   Updated: 2024/01/28 14:26:30 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BITWISE_H
# define FT_BITWISE_H

# include <stdbool.h>

inline unsigned int	ft_bit_set(unsigned int number, unsigned int n)
{
	return (number | ((unsigned int)1 << n));
}

inline unsigned int	ft_bit_clear(unsigned int number, unsigned int n)
{
	return (number & ~((unsigned int)1 << n));
}

inline unsigned int	ft_bit_toggle(unsigned int number, unsigned int n)
{
	return (number ^ ((unsigned int)1 << n));
}

inline bool	ft_bit_check(unsigned int number, unsigned int n)
{
	return ((number >> n) & (unsigned int)1);
}

inline unsigned int	ft_bit_set_to(unsigned int number, unsigned int n, bool x)
{
	return ((number & ~((unsigned int)1 << n)) | ((unsigned int)x << n));
}

#endif
