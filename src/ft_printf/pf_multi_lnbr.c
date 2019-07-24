/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_multi_lnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 02:55:57 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/28 05:13:03 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_multi(int *tmp_len, int *i, t_lnbr *res)
{
	*i = 0;
	*tmp_len = 0;
	res->len = 0;
	ft_bzero(res->vls, sizeof(res->vls));
}

void		multi_lnbr(t_lnbr *a, t_lnbr *b)
{
	int		i;
	int		j;
	int		tmp_len;
	int		over;
	t_lnbr	res;

	set_multi(&tmp_len, &i, &res);
	while (i < a->len)
	{
		over = 0;
		j = 0;
		while (j < b->len)
		{
			res.vls[i + j] += a->vls[i] * b->vls[j] + over;
			over = res.vls[i + j] / 10;
			res.vls[i + j] %= 10;
			j++;
			tmp_len++;
		}
		if (over)
			res.vls[tmp_len++] = over;
		res.len += tmp_len - res.len;
		tmp_len = ++i;
	}
	*a = res;
}
