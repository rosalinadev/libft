/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitwise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 13:25:06 by rvandepu          #+#    #+#             */
/*   Updated: 2024/01/28 14:27:24 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "ft_bitwise.h"

// https://stackoverflow.com/a/47990
// https://stackoverflow.com/a/10291700

extern unsigned int	ft_bit_set(unsigned int number, unsigned int n);
extern unsigned int	ft_bit_clear(unsigned int number, unsigned int n);
extern unsigned int	ft_bit_toggle(unsigned int number, unsigned int n);
extern bool			ft_bit_check(unsigned int number, unsigned int n);
extern unsigned int	ft_bit_set_to(unsigned int number, unsigned int n, bool x);
