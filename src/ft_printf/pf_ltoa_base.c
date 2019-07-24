/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 22:25:47 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/26 02:32:06 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	pf_ulonglen_base(u_int64_t n, char base)
{
	size_t	len;

	len = 0;
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

static void		pf_ltoa_zero(t_res *res)
{
	res->len = 1;
	if ((res->str = (char *)malloc(sizeof(char) * res->len)))
		res->str[0] = '0';
	else
		res->len = -1;
}

static void		pf_ltoa_nbr(t_res *res, unsigned long nbr, char base, char type)
{
	size_t		i;

	res->len = pf_ulonglen_base(nbr, base);
	if ((res->str = (char *)malloc(sizeof(char) * res->len)))
	{
		i = res->len - 1;
		while (nbr)
		{
			if (nbr % base > 9)
				res->str[i--] = nbr % base + type;
			else
				res->str[i--] = nbr % base + 48;
			nbr /= base;
		}
	}
	else
		res->len = -1;
}

t_res			pf_ltoa_base(unsigned long nbr, char base, t_ftask *ftask)
{
	t_res		res;

	res.str = NULL;
	res.len = 0;
	if (nbr == 0)
		pf_ltoa_zero(&res);
	else
		pf_ltoa_nbr(&res, nbr, base, (ftask->type == 'X') ? 55 : 87);
	if (ftask->prc > 0)
		set_prc(&res, ftask->prc);
	return (res);
}
