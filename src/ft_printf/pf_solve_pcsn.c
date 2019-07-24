/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_solve_pcsn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 22:40:15 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/16 16:28:01 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_res	solve_ptr(t_ftask *ftask, unsigned long ptr)
{
	t_res	res;
	t_res	nbr;

	res.str = NULL;
	res.len = 0;
	if (ptr == 0 && ftask->prc == 0)
		nbr.len = 0;
	else
		nbr = pf_ltoa_base(ptr, 16, ftask);
	res.len = nbr.len + 2;
	if (nbr.len != -1 && (res.str = (char *)malloc(sizeof(char) * res.len)))
	{
		res.str[0] = '0';
		res.str[1] = 'x';
		ft_memcpy(res.str + 2, nbr.str, nbr.len);
		if (ftask->prc == -1 && ftask->flags.zero && ftask->width > res.len)
			set_zero(&res, ftask->width);
		else if (ftask->width > res.len)
			set_width(&res, ftask, ' ');
	}
	else
		res.len = -1;
	if (nbr.len)
		ft_strdel(&nbr.str);
	return (res);
}

t_res	solve_str(t_ftask *ftask, char *str)
{
	t_res	res;

	res.str = NULL;
	res.len = 0;
	if (ftask->prc)
	{
		if (str == NULL)
		{
			res.len = (ftask->prc > 0 && ftask->prc < 6) ? ftask->prc : 6;
			res.str = (char *)ft_memdup("(null)", res.len);
		}
		else
		{
			res.len = ft_strlen(str);
			res.len = (ftask->prc > 0 && ftask->prc < res.len)
			? ftask->prc : res.len;
			res.str = (char *)ft_memdup(str, res.len);
		}
		if (!res.str)
			res.len = -1;
	}
	if (ftask->width > res.len)
		set_width(&res, ftask, (ftask->flags.zero) ? '0' : ' ');
	return (res);
}

t_res	solve_char(t_ftask *ftask, unsigned char c)
{
	t_res	res;

	res.str = NULL;
	res.len = (ftask->width) ? ftask->width : 1;
	if ((res.str = (char *)malloc(sizeof(char) * res.len)))
	{
		if (ftask->width)
		{
			(ftask->flags.zero) ? ft_memset(res.str, '0', res.len)
			: ft_memset(res.str, ' ', res.len);
			if (ftask->flags.minus)
				res.str[0] = c;
			else
				res.str[res.len - 1] = c;
		}
		else
			res.str[0] = c;
	}
	else
		res.len = -1;
	return (res);
}

t_res	solve_noconv(t_ftask *ftask)
{
	t_res	res;

	res.str = NULL;
	res.len = 1;
	if ((res.str = (char *)malloc(sizeof(char) * res.len)))
	{
		res.str[0] = ftask->type;
		if (ftask->flags.zero && ftask->width > res.len)
			set_zero(&res, ftask->width);
		else if (ftask->width > res.len)
			set_width(&res, ftask, ' ');
	}
	else
		res.len = -1;
	return (res);
}

t_res	set_arg_string(t_ftask *ftask, va_list *args)
{
	if ((ftask->type == 'c' && ftask->size.chr == 'l')
	|| ftask->type == 'C')
		return (solve_uchar(ftask, va_arg(*args, wchar_t)));
	else if (ftask->type == 'c')
		return (solve_char(ftask, va_arg(*args, int)));
	else if ((ftask->type == 's' && ftask->size.chr == 'l')
	|| ftask->type == 'S')
		return (solve_ustr(ftask, va_arg(*args, wchar_t *)));
	return (solve_str(ftask, va_arg(*args, char *)));
}
