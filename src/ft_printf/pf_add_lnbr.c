/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_add_lnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:10:07 by nalexand          #+#    #+#             */
/*   Updated: 2019/05/27 03:26:18 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	div_add(t_lnbr *a, t_lnbr *b, int i, int j)
{
	int		over;

	over = 0;
	while (j < a->len || j < b->len)
	{
		a->vls[j] += (j < b->len) ? b->vls[i++] + over : 0;
		if (a->vls[j] > 9)
		{
			over = a->vls[j] / 10;
			a->vls[j] %= 10;
		}
		else if (over)
			over = 0;
		j++;
	}
	a->len = j;
	if (over)
		a->vls[a->len++] = over;
}

static void	mod_add(t_lnbr *a, t_lnbr *b, int i, int j)
{
	int		k;
	int		over;

	i = a->len - 1;
	j = b->len - 1;
	while (j >= 0)
	{
		if (i >= 0)
			a->vls[j] = a->vls[i--] + b->vls[j];
		else
			a->vls[j] = b->vls[j];
		if (a->vls[j] > 9)
		{
			k = j;
			over = a->vls[k] / 10;
			while (over && (k < b->len || k < a->len))
			{
				a->vls[k++] %= 10;
				a->vls[k] += over;
				over = a->vls[k] / 10;
			}
		}
		j--;
	}
	a->len = b->len;
}

void		add_lnbr(t_lnbr *a, t_lnbr *b)
{
	if ((a->len == 1 && a->vls[0] == 0)
	|| (a->len == 2 && a->vls[0] == 0 && a->vls[1] == 0))
		ft_memcpy(a->vls, b->vls, (a->len = b->len) * 4);
	else if (a->vls[a->len - 1] && b->vls[b->len - 1])
		div_add(a, b, 0, 0);
	else
		mod_add(a, b, 0, 0);
}
