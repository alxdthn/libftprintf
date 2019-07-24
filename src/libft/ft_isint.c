/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:16:30 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/16 16:27:29 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_sign(char **nb)
{
	char	sign;

	sign = '+';
	if (**nb == '-' || **nb == '+')
	{
		if (**nb == '-')
			sign = '-';
		(*nb)++;
	}
	return (sign);
}

static int	is_zero(char **nb)
{
	char	last;

	if (**nb == '0')
	{
		last = '0';
		while (**nb == '0')
		{
			last = **nb;
			(*nb)++;
		}
		if (!ft_isdigit(**nb) && last == '0')
			return (1);
	}
	return (0);
}

static int	get_len(char *nb)
{
	int		len;
	size_t	i;

	i = 0;
	len = 0;
	while (ft_isdigit(nb[i]))
	{
		len++;
		i++;
	}
	return (len);
}

static int	check_min_max(char *nb, int len, char sign)
{
	char	*mask;

	if (len == 10)
	{
		if (sign == '+')
			mask = "2147483647";
		else
			mask = "2147483648";
		if (ft_strcmp(nb, mask) <= 0)
			return (0);
		else
			return (1);
	}
	return (0);
}

int			ft_isint(char *nb)
{
	int		len;
	char	sign;

	sign = get_sign(&nb);
	if (is_zero(&nb))
		return (1);
	len = get_len(nb);
	if (len > 10 || len == 0)
		return (0);
	if (check_min_max(nb, len, sign))
		return (0);
	return (1);
}
