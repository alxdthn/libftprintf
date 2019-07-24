/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_float_div.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 11:36:23 by nalexand          #+#    #+#             */
/*   Updated: 2019/05/28 11:28:12 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		pos_pow_of_two(t_lnbr *pow, t_lnbr *factor, int *max, char p)
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
		add_lnbr(pow, pow);
		(*max)--;
	}
}

static void	solve_mantissa_div(t_lnbr *div, t_lnbr *pow, t_ems *uni)
{
	int		pow_val;

	pow_val = uni->ems.e - 16383;
	while (uni->ems.m)
	{
		if ((uni->ems.m & 1) == 1)
			add_lnbr(div, pow);
		uni->ems.m >>= 1;
		pos_pow_of_two(pow, NULL, &pow_val, 0);
	}
}

void		get_float_div(t_lnbr *div, t_ems uni)
{
	t_lnbr	cur_pow;
	t_lnbr	factor;
	int		pow;

	*div = set_lnbr("0");
	cur_pow = set_lnbr("1");
	if ((pow = uni.ems.e - 16383) < 0)
		return ;
	if (pow < 64)
		uni.ems.m >>= (63 - pow);
	else
	{
		factor = set_lnbr("2");
		pow -= 63;
		while (pow)
			pos_pow_of_two(&cur_pow, &factor, &pow, 1);
	}
	solve_mantissa_div(div, &cur_pow, &uni);
}
