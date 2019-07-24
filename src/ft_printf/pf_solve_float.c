/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_solve_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihail <mihail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 17:10:31 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/23 17:32:41 by mihail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_ldbl(t_res *res, t_ems *uni, char type)
{
	if (uni->ems.e == 0x7FFF)
	{
		res->len = 3;
		if (uni->ems.m >> 62 == 0)
		{
			if (uni->ems.m == 0)
				res->str = (type == 'f') ? ft_strdup("inf") : ft_strdup("INF");
			else
				res->str = (type == 'f') ? ft_strdup("nan") : ft_strdup("NAN");
		}
		else if (uni->ems.m >> 62 == 2)
		{
			if (uni->ems.m << 2 == 0)
				res->str = (type == 'f') ? ft_strdup("inf") : ft_strdup("INF");
			else
				res->str = (type == 'f') ? ft_strdup("nan") : ft_strdup("NAN");
		}
		else if (uni->ems.m >> 62 == 1 || uni->ems.m >> 62 == 3)
			res->str = (type == 'f') ? ft_strdup("nan") : ft_strdup("NAN");
		if (!res->str)
			res->len = -1;
	}
}

static void	set_params_float(t_res *res, t_ems *uni, t_ftask *ftask)
{
	if (res->str[0] == 'n' || res->str[0] == 'N')
	{
		ftask->flags.plus = 0;
		ftask->flags.zero = 0;
		ftask->flags.space = 0;
		uni->ems.s = 0;
	}
	if (res->str[0] == 'i' || res->str[0] == 'I')
		ftask->flags.zero = 0;
	ftask->prc = -1;
	if (res->str && (ftask->flags.plus || ftask->flags.space || uni->ems.s))
		set_sign(res, ftask, -uni->ems.s);
	if (res->str && ftask->flags.zero && ftask->width > res->len)
		set_zero(res, ftask->width);
	else if (ftask->width > res->len)
		set_width(res, ftask, ' ');
}

t_res		solve_float(t_ftask *ftask, va_list *args)
{
	long double	ldbl;
	t_ems		uni;
	t_res		res;

	if (ftask->size.chr == 'f')
		ldbl = va_arg(*args, long double);
	else
		ldbl = va_arg(*args, double);
	uni.ldbl = ldbl;
	res.len = 0;
	res.str = NULL;
	check_ldbl(&res, &uni, ftask->type);
	if (ftask->prc)
		ftask->prc = (ftask->prc == -1) ? 7 : ftask->prc + 1;
	if (!res.str && res.len != -1)
		get_ldbl(&res, ftask, &uni);
	if (res.len != -1)
		set_params_float(&res, &uni, ftask);
	return (res);
}
