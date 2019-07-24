/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_float_mod.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 18:35:27 by nalexand          #+#    #+#             */
/*   Updated: 2019/05/28 11:43:24 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		multi_on_five(t_lnbr *pow_data)
{
	int		i;
	int		over;
	int		tmp;
	int		s;

	s = pow_data->len - 1;
	while (!pow_data->vls[s])
		s--;
	i = 0;
	over = 0;
	while (i <= s + 1)
	{
		if (pow_data->vls[i] > 0)
			tmp = pow_data->vls[i] * 5;
		else
			tmp = 0;
		pow_data->vls[i] = tmp % 10 + over;
		over = tmp / 10;
		i++;
	}
	pow_data->len++;
}

void		neg_pow_of_two(t_lnbr *pow, t_lnbr *factor, int *max, char p)
{
	if (p && (*max % 2) == 1)
	{
		multi_lnbr(pow, factor);
		(*max)--;
	}
	else if (p && (*max % 2) == 0)
	{
		multi_lnbr(factor, factor);
		(*max) /= 2;
	}
	else
	{
		multi_on_five(pow);
		(*max)--;
	}
}

static void	solve_mantissa_mod(t_lnbr *mod, t_lnbr *cur_pow, t_ems *uni)
{
	int		pow;

	pow = uni->ems.e - 16383;
	while (uni->ems.m)
	{
		if ((uni->ems.m & 0x8000000000000000) == 0x8000000000000000)
			add_lnbr(mod, cur_pow);
		neg_pow_of_two(cur_pow, NULL, &pow, 0);
		uni->ems.m <<= 1;
	}
}

void		get_float_mod(t_lnbr *mod, t_ems uni, int prc)
{
	int		pow;
	t_lnbr	cur_pow;
	t_lnbr	factor;

	*mod = set_lnbr("00");
	pow = uni.ems.e - 16383;
	if (pow >= 63 || pow == -16383)
		return ;
	cur_pow = set_lnbr("1");
	if (pow < 0)
	{
		pow = -pow;
		if (pow / 3 > prc + ACC)
			return ;
		factor = set_lnbr("05");
		while (pow)
			neg_pow_of_two(&cur_pow, &factor, &pow, 1);
	}
	else
	{
		cur_pow = set_lnbr("05");
		uni.ems.m <<= pow + 1;
	}
	solve_mantissa_mod(mod, &cur_pow, &uni);
}
