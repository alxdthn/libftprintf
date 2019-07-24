/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_set_arg_digit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 01:51:16 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/26 02:32:06 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	set_unsigned_arg(t_ftask *ftask, va_list *args)
{
	long	arg;

	if (ftask->type == 'U' || ftask->type == 'O' || ftask->size.chr == 'l')
		arg = (long)va_arg(*args, unsigned long);
	else if (ftask->size.chr == 'L' || ftask->size.chr == 'j')
		arg = (long)va_arg(*args, unsigned long long);
	else if (ftask->size.chr == 'z')
		arg = (long)va_arg(*args, size_t);
	else
		arg = (long)va_arg(*args, unsigned int);
	if (ftask->size.chr == 'h')
		arg = (long)((unsigned short)arg);
	else if (ftask->size.chr == 'H')
		arg = (long)((unsigned char)arg);
	return (arg);
}

t_res		set_arg_digit(t_ftask *ftask, va_list *args)
{
	long	arg;

	if (ftask->type == 'd' || ftask->type == 'i' || ftask->type == 'D')
	{
		if (ftask->type == 'D' || ftask->size.chr == 'l')
			arg = (long)va_arg(*args, long);
		else if (ftask->size.chr == 'L' || ftask->size.chr == 'j')
			arg = (long)va_arg(*args, long long);
		else if (ftask->size.chr == 'z')
			arg = (long)va_arg(*args, ssize_t);
		else
			arg = (long)va_arg(*args, int);
		if (ftask->size.chr == 'h')
			arg = (long)((short)arg);
		else if (ftask->size.chr == 'H')
			arg = (long)((char)arg);
	}
	else
		arg = set_unsigned_arg(ftask, args);
	return (solve_digit(ftask, arg));
}
