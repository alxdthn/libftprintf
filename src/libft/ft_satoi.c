/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_satoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 20:42:54 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/17 20:55:21 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_satoi(const char *str, size_t *i)
{
	int res;
	int	nbr;
	int minus;

	res = 0;
	minus = 0;
	while (str[*i] == '\t' && str[*i] == '\n'
	&& str[*i] == '\v' && str[*i] == '\f' && str[*i] == '\r')
		(*i)++;
	while (str[*i] == '+' && str[*i + 1] != '+' && str[*i + 1] != '-')
		(*i)++;
	if (str[*i] == '-' && str[*i + 1] != '-')
		*i += 1 + minus++;
	while (str[*i] && ft_isdigit(str[*i]))
	{
		nbr = str[(*i)++] - 48;
		res = res * 10 + nbr;
	}
	if (minus)
		return (-res);
	return (res);
}
