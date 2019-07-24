/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 08:21:20 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/09 08:24:03 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	convert_and_check_nb(char c, int base)
{
	int		result;

	if (c >= '0' && c <= '9')
		result = c - 48;
	else if (c >= 'a' && c <= 'z')
		result = c - 97 + 10;
	else if (c >= 'A' && c <= 'Z')
		result = c - 65 + 10;
	else
		result = -1;
	if (result < base && result != -1)
		return (result);
	else
		return (-1);
}

static int	length_number(char *str, int base)
{
	int		length;

	length = 0;
	while (str[length])
	{
		if (convert_and_check_nb(str[length], base) == -1)
			break ;
		length++;
	}
	return (length);
}

int			ft_atoi_base(char *nb, int base)
{
	int		result;
	int		length;

	if (base == 10)
		return (ft_atoi(nb));
	nb = ft_strsskp(nb, " \t\n\v\r\f");
	result = 0;
	length = length_number(nb, base) - 1;
	while (*nb && length >= 0 && convert_and_check_nb(*nb, base) != -1)
	{
		result += convert_and_check_nb(*nb, base) * ft_power(base, length);
		nb++;
		length--;
	}
	return (result);
}
