/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 02:42:37 by nalexand          #+#    #+#             */
/*   Updated: 2019/05/13 15:30:10 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	btoa_set_char(__int128_t *bits, int *count_bits, char param)
{
	char	res;

	if (param && *count_bits == 4)
	{
		res = ' ';
		*count_bits = 0;
		return (res);
	}
	else if ((*bits & 1) == 1)
		res = '1';
	else
		res = '0';
	(*count_bits)++;
	(*bits) >>= 1;
	return (res);
}

char		*ft_btoa(__int128_t bits, size_t len, char param)
{
	size_t	i;
	int		count_bits;
	char	*res;

	i = 0;
	if (param)
		len += len / 4;
	if (!(res = ft_strnew(len)))
		return (NULL);
	count_bits = 0;
	while (i < len)
		res[i++] = btoa_set_char(&bits, &count_bits, param);
	res[i - 1] = '\0';
	if (!(res = ft_strrev(res)))
		return (NULL);
	return (res);
}
