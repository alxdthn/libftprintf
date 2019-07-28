/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 22:38:38 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/29 02:21:23 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_flags(char fmt, t_ftask *ftask)
{
	if (fmt == '#')
		return (ftask->flags.sharp = 1);
	else if (fmt == '-')
		return (ftask->flags.minus = 1);
	else if (fmt == '+')
		return (ftask->flags.plus = 1);
	else if (fmt == ' ')
		return (ftask->flags.space = 1);
	else if (fmt == '0')
		return (ftask->flags.zero = 1);
	return (0);
}

void		get_width(char **fmt, t_ftask *ftask, va_list *args)
{
	long	tmp;

	if (**fmt == '*')
	{
		if ((tmp = va_arg(*args, int)) < INT32_MAX && tmp > INT32_MIN + 1L)
		{
			if (tmp < 0)
			{
				ftask->width = -tmp;
				ftask->flags.minus = 1;
			}
			else
				ftask->width = tmp;
		}
		while (**fmt && **fmt == '*')
			(*fmt)++;
	}
	else
	{
		ftask->width = ft_atoi(*fmt);
		while (**fmt && ft_isdigit(**fmt))
			(*fmt)++;
		if (ftask->width < 0)
			ftask->width = 0;
	}
}

void		get_prc(char **fmt, int *prc, va_list *args)
{
	long	tmp;

	while (**fmt == '.')
		(*fmt)++;
	if (**fmt == '*')
	{
		if ((tmp = va_arg(*args, int)) < INT32_MAX && tmp > INT32_MIN + 1L)
			*prc = tmp;
		else
			*prc = 0;
	}
	else
		*prc = ft_atoi(*fmt);
	if (*prc < 0)
		*prc = -1;
	while (ft_isdigit(**fmt) || **fmt == '*')
		(*fmt)++;
}

static void	set_params_size(t_size *size, char **fmt, char chr, size_t value)
{
	size->chr = chr;
	size->value = value;
	(*fmt) += (chr > 76 || chr == 70) ? 1 : 2;
}

void		get_size(char **fmt, t_size *size)
{
	t_size	tmp_size;

	tmp_size.chr = 0;
	tmp_size.value = 4;
	if (**fmt == 'h' && *(*fmt + 1) != 'h')
		set_params_size(&tmp_size, fmt, 'h', sizeof(short));
	else if (**fmt == 'h' && *(*fmt + 1) == 'h')
		set_params_size(&tmp_size, fmt, 'H', sizeof(char));
	else if (**fmt == 'l' && *(*fmt + 1) != 'l')
		set_params_size(&tmp_size, fmt, 'l', sizeof(long));
	else if (**fmt == 'l' && *(*fmt + 1) == 'l')
		set_params_size(&tmp_size, fmt, 'L', sizeof(long long));
	else if (**fmt == 'L')
		set_params_size(&tmp_size, fmt, 'f', sizeof(long double));
	else if (**fmt == 'j')
		set_params_size(&tmp_size, fmt, 'j', sizeof(long long));
	else if (**fmt == 'z')
		set_params_size(&tmp_size, fmt, 'z', sizeof(size_t));
	if (size->chr)
	{
		if (size->value < tmp_size.value)
			*size = tmp_size;
	}
	else
		*size = tmp_size;
}
