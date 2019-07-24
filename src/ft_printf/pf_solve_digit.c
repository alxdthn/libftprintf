/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_solve_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 22:03:03 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/26 02:32:06 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_sharp_hex(t_res *res, t_ftask *ftask)
{
	t_res	tmp;

	if (res->len == -1)
		return ;
	tmp.str = NULL;
	tmp.len = res->len + 2;
	if ((tmp.str = (char *)malloc(sizeof(char) * tmp.len)))
	{
		tmp.str[0] = '0';
		tmp.str[1] = ftask->type;
		ft_memcpy(tmp.str + 2, res->str, res->len);
	}
	else
		tmp.len = -1;
	ft_strdel(&res->str);
	*res = tmp;
}

static void	set_sharp_octal(t_res *res, t_ftask *ftask)
{
	t_res	tmp;

	if ((res->str && res->str[0] == '0') || res->len == -1)
		return ;
	tmp.str = NULL;
	tmp.len = res->len + 1;
	if ((tmp.str = (char *)malloc(sizeof(char) * tmp.len)))
	{
		tmp.str[0] = '0';
		ft_memcpy(tmp.str + 1, res->str, res->len);
		if (ftask->prc == -1 && ftask->flags.zero &&
		ftask->width > res->len && !ftask->flags.minus)
			set_zero(&tmp, ftask->width);
	}
	else
		tmp.len = -1;
	ft_strdel(&res->str);
	*res = tmp;
}

static void	set_params(t_res *res, t_ftask *ftask, long nbr)
{
	if (res->len != -1)
	{
		if (ftask->flags.sharp && (ftask->type == 'o' || ftask->type == 'O'))
			set_sharp_octal(res, ftask);
		if (nbr && ftask->flags.sharp
		&& (ftask->type == 'x' || ftask->type == 'X'))
			set_sharp_hex(res, ftask);
		if ((ftask->flags.plus || ftask->flags.space || nbr < 0)
		&& ft_strchr("dDi", ftask->type))
			set_sign(res, ftask, nbr);
		if (ftask->prc == -1 && ftask->flags.zero && ftask->width > res->len)
			set_zero(res, ftask->width);
		else if (ftask->width > res->len)
			set_width(res, ftask, ' ');
	}
}

t_res		solve_digit(t_ftask *ftask, long arg)
{
	char			base;
	unsigned long	nbr;
	t_res			res;

	res.str = NULL;
	res.len = 0;
	if (!ftask->prc && !arg)
		set_params(&res, ftask, arg);
	else
	{
		base = 10;
		if (ft_strchr("oO", ftask->type))
			base = 8;
		else if (ft_strchr("xX", ftask->type))
			base = 16;
		if (arg < 0 && ft_strchr("dDi", ftask->type))
			nbr = -arg;
		else
			nbr = arg;
		res = pf_ltoa_base(nbr, base, ftask);
		set_params(&res, ftask, arg);
	}
	return (res);
}
