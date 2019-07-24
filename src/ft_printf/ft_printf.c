/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 21:53:29 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/16 16:18:37 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_res	solve_ftask(t_ftask *ftask, va_list *args)
{
	if (ft_strchr("cCsS", ftask->type))
		return (set_arg_string(ftask, args));
	else if (ftask->type == 'p')
		return (solve_ptr(ftask, (unsigned long)va_arg(*args, void *)));
	else if (ft_strchr("dDioOuUxX", ftask->type))
		return (set_arg_digit(ftask, args));
	else if (ftask->type == 'f' || ftask->type == 'F')
		return (solve_float(ftask, args));
	else if (ftask->type == 'b')
		return (solve_bits(ftask, args));
	return (solve_noconv(ftask));
}

static int		print_out(t_out *out, va_list *args)
{
	int		ret;

	ret = 0;
	if (out->res.len)
		ret += out->res.len;
	if (out->ftask.type)
	{
		out->res = solve_ftask(&out->ftask, args);
		if (out->res.len == -1)
			return (-1);
		if (out->res.str)
		{
			write(1, out->res.str, out->res.len);
			ret += out->res.len;
			ft_strdel(&out->res.str);
		}
		if (out->ftask.clr)
		{
			out->ftask.clr = EOC;
			solve_color(out->ftask.clr, args);
			out->ftask.clr = NULL;
		}
	}
	return (ret);
}

int				ft_printf(char *fmt, ...)
{
	t_out	out;
	va_list	args;
	int		ret;
	int		buf;

	if (!fmt)
		return (-1);
	ret = 0;
	va_start(args, fmt);
	out_new(&out);
	while (*fmt && ret != -1)
	{
		if (out.ftask.type)
			out_new(&out);
		buf = parse(&fmt, &out, &args);
		ret = (buf == -1) ? buf : ret + buf;
		buf = print_out(&out, &args);
		ret = (buf == -1) ? buf : ret + buf;
	}
	va_end(args);
	return (ret);
}
