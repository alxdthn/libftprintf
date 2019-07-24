/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_solve_unicode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 03:15:16 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/26 02:32:06 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_size(int *size, int value)
{
	if (value >= 65536)
		*size = 4;
	else if (value >= 2048)
		*size = 3;
	else if (value >= 128)
		*size = 2;
	else
		*size = 1;
}

void		set_unicode(t_res *res, wchar_t *u_str, int count, int prc)
{
	int		i;
	int		size;
	char	buf[4];

	res->len = unicode_len(u_str, count, prc);
	if ((res->str = (char *)malloc(sizeof(char) * res->len)))
	{
		i = 0;
		while (*u_str && count && i < (*res).len)
		{
			set_size(&size, *u_str);
			get_uchar((char *)&buf, *u_str, size);
			ft_memcpy(res->str + i, buf, size);
			i += size;
			u_str++;
			if (count > 0)
				count--;
		}
	}
	else
		res->len = -1;
}

t_res		solve_ustr(t_ftask *ftask, wchar_t *ustr)
{
	t_res	res;

	res.str = NULL;
	res.len = 0;
	if (ustr == NULL)
	{
		if (ftask->prc > 6 || ftask->prc == -1)
			res.len = 6;
		else
			res.len = ftask->prc;
		if (!(res.str = ft_memdup("(null)", res.len)))
			res.len = -1;
	}
	else
		set_unicode(&res, ustr, -1, ftask->prc);
	if (ftask->width > res.len)
		set_width(&res, ftask, (ftask->flags.zero) ? '0' : ' ');
	return (res);
}

t_res		solve_uchar(t_ftask *ftask, wchar_t uchar)
{
	t_res	res;

	res.str = NULL;
	res.len = 0;
	if (uchar == 0)
	{
		res.len = 1;
		if (!(res.str = (char *)ft_memalloc(sizeof(char) * res.len)))
			res.len = -1;
	}
	else
		set_unicode(&res, &uchar, 1, -1);
	if (ftask->width > res.len)
		set_width(&res, ftask, (ftask->flags.zero) ? '0' : ' ');
	return (res);
}
