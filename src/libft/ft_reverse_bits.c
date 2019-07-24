/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_bits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 13:25:42 by nalexand          #+#    #+#             */
/*   Updated: 2019/05/27 01:45:00 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_reverse_bits(unsigned long bits, size_t size)
{
	unsigned long	res;

	size *= 8;
	res = 0;
	while (size--)
	{
		res = (res << 1) | (bits & 1);
		bits >>= 1;
	}
	return (res);
}
