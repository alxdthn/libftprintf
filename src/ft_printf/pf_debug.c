/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihail <mihail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 02:10:10 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/23 17:41:32 by mihail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*show_lnbr(t_lnbr nbr)
{
	char	*res;
	int		i;
	int		j;

	if ((res = (char *)ft_strnew(nbr.len)))
	{
		i = 0;
		j = nbr.len - 1;
		while (i < nbr.len)
			res[i++] = nbr.vls[j--] + 48;
	}
	return (res);
}

void	print_lnbr(t_lnbr nbr)
{
	int		i;

	ft_putstr("len: ");
	ft_putnbr(nbr.len);
	ft_putchar(' ');
	i = nbr.len - 1;
	while (i >= 0)
	{
		if (nbr.vls[i] == -1)
			ft_putchar('.');
		else
			ft_putchar(nbr.vls[i] + 48);
		i--;
	}
}

int		print_ldbl_ems(t_ems uni, char param)
{
	char	*tmp;
	int		ret;

	if (!(tmp = ft_btoa(uni.ldbl, 80, param)))
		return (-1);
	ret = ft_printf("%s\n", tmp);
	ft_strdel(&tmp);
	if (!(tmp = ft_btoa(uni.ems.s, 8, param)))
		return (-1);
	ret += ft_printf("sign      %-45d%s\n", uni.ems.s, tmp);
	ft_strdel(&tmp);
	if (!(tmp = ft_btoa(uni.ems.e, 16, param)))
		return (-1);
	ret += ft_printf("expo      %-20d = %-22d%s\n",
					uni.ems.e, uni.ems.e - 16383, tmp);
	ft_strdel(&tmp);
	if (!(tmp = ft_btoa(uni.ems.m, 64, param)))
		return (-1);
	ret += ft_printf("mant      %-20llu = %-22llu%s\n",
					uni.ems.m, ft_reverse_bits(uni.ems.m, 64), tmp);
	ft_strdel(&tmp);
	return (ret);
}
