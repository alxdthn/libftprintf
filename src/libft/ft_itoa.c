/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 07:31:06 by nalexand          #+#    #+#             */
/*   Updated: 2019/05/01 16:36:19 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_zero_chr(void)
{
	char	*res;

	if (!(res = (char *)ft_strnew(sizeof(char))))
		return (NULL);
	res[0] = '0';
	return (res);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		size;
	int		minus;
	long	nbr;

	if (!(nbr = n) || nbr < -2147483648 || nbr > 2147483647)
		return (ft_zero_chr());
	minus = 0;
	size = ft_intlen(nbr);
	if (nbr < 0)
		nbr *= -1 + minus++;
	if (!(res = (char *)ft_strnew(sizeof(*res) * size)))
		return (NULL);
	size = size - 1;
	while (size > 0)
	{
		res[size] = nbr % 10 + 48;
		size--;
		nbr /= 10;
	}
	if (minus)
		res[size] = '-';
	else
		res[size] = nbr % 10 + 48;
	return (res);
}
