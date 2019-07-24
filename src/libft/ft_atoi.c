/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 08:23:19 by nalexand          #+#    #+#             */
/*   Updated: 2019/04/12 00:25:01 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_long_check(const char *str, int minus)
{
	int count;

	count = 0;
	while (ft_isdigit(*str) && count < 20)
	{
		str++;
		count++;
		if (count >= 20 && minus)
			return (0);
		else if (count >= 20 && !minus)
			return (-1);
	}
	if (count == 19 && minus && *(str - 1) > '8')
		return (0);
	else if (count == 19 && !minus && *(str - 1) > '7')
		return (-1);
	return (1);
}

int			ft_atoi(const char *str)
{
	int res;
	int	nbr;
	int minus;

	res = 0;
	minus = 0;
	str = ft_strsskp(str, " \t\n\v\f\r");
	while (*str == '+' && *(str + 1) != '+' && *(str + 1) != '-')
		str++;
	if (*str == '-' && *(str + 1) != '-')
		str = str + 1 + minus++;
	if ((nbr = ft_long_check(str, minus)) != 1)
		return (nbr);
	while (*str && ft_isdigit(*str))
	{
		nbr = *(str++) - 48;
		res = res * 10 + nbr;
	}
	if (minus)
		return (-res);
	return (res);
}
