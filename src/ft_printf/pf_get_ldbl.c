/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_ldbl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 00:39:22 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/28 05:11:46 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		rounding(t_lnbr *nbr, int point)
{
	ssize_t		over;

	nbr->vls[point++] = 0;
	over = 1;
	while (over && point < nbr->len)
	{
		nbr->vls[point] += over;
		over = nbr->vls[point] / 10;
		nbr->vls[point++] %= 10;
	}
}

static void		round_mod(t_lnbr *nbr, char div_value, int prc)
{
	ssize_t	point;
	int		value;

	point = nbr->len - 1 - ((prc == 0) ? 1 : prc);
	if (nbr->len < prc || point < 0)
		return ;
	value = (prc == 0) ? div_value : nbr->vls[point + 1];
	if (nbr->vls[point] == 5 && (value % 2 != 0 || value == 0))
		rounding(nbr, point);
	else if (nbr->vls[point] == 5 && point != 0)
		rounding(nbr, point);
	else if (nbr->vls[point] > 5)
		rounding(nbr, point);
}

static t_res	std_core(t_lnbr *div, t_lnbr *mod, t_ftask *ftask)
{
	t_res	res;
	int		i;
	int		j;
	int		k;

	res.str = NULL;
	res.len = div->len + ftask->prc + ((!ftask->prc) ? ftask->flags.sharp : 0);
	if ((res.str = (char *)malloc(sizeof(char) * res.len)))
	{
		ft_memset(res.str, '0', res.len);
		i = div->len - 1;
		j = mod->len - 1;
		k = 0;
		while (i >= 0 && k < res.len)
			res.str[k++] = div->vls[i--] + 48;
		mod->vls[j] = -2;
		while (j >= 0 && k < res.len)
			res.str[k++] = mod->vls[j--] + 48;
	}
	else
		res.len = -1;
	return (res);
}

void			set_over(t_lnbr *nbr, int over)
{
	int		i;

	i = 0;
	nbr->vls[i++] %= 10;
	while (over && i < nbr->len)
	{
		nbr->vls[i] += over;
		over = nbr->vls[i] / 10;
		nbr->vls[i++] %= 10;
	}
	if (over)
		nbr->vls[nbr->len++] = over;
}

void			get_ldbl(t_res *res, t_ftask *ftask, t_ems *uni)
{
	t_lnbr	div;
	t_lnbr	mod;

	get_float_div(&div, *uni);
	get_float_mod(&mod, *uni, ftask->prc);
	res->str = NULL;
	res->len = 0;
	round_mod(&mod, div.vls[0], ftask->prc);
	if (mod.vls[mod.len - 1])
	{
		div.vls[0] += mod.vls[mod.len - 1];
		if (div.vls[0] > 9)
			set_over(&div, div.vls[0] / 10);
	}
	*res = std_core(&div, &mod, ftask);
}
