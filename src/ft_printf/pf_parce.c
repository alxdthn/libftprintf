/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parce.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 22:30:06 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/26 02:32:06 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	validation_ftask(t_ftask *ftask)
{
	if (ftask->flags.minus)
		ftask->flags.zero = 0;
	if (ft_strchr("%cCsSp", ftask->type))
	{
		ftask->flags.sharp = 0;
	}
	if (ft_strchr("oxX", ftask->type))
	{
		ftask->flags.space = 0;
		ftask->flags.plus = 0;
	}
	if (ftask->type == 'O' || ftask->type == 'D' || ftask->type == 'U')
		ftask->size.chr = 0;
}

static int	get_type(char **fmt, char *type)
{
	if (!ft_strchr(ALL_PARAM, **fmt))
	{
		*type = **fmt;
		(*fmt)++;
		return (1);
	}
	return (0);
}

int			find_type(char *fmt)
{
	int		i;

	i = 0;
	while (fmt[i])
	{
		if (ft_strchr(ALL_PARAM, fmt[i]))
			i++;
		else
		{
			if (ft_strchr(TYPES, fmt[i]))
				return (1);
			return (0);
		}
	}
	return (0);
}

static int	parse_ftask(char **fmt, t_ftask *ftask, va_list *args)
{
	int		ret;

	ret = 0;
	while (**fmt)
	{
		if (**fmt == '{')
		{
			ret += parse_color(fmt, ftask, args);
			if (**fmt == '%')
				break ;
		}
		if (get_type(fmt, &ftask->type) || ftask->type)
			break ;
		if (get_flags(**fmt, ftask))
			(*fmt)++;
		if (**fmt != '0' && (ft_isdigit(**fmt) || **fmt == '*'))
			get_width(fmt, ftask, args);
		if (**fmt == '.')
			get_prc(fmt, &ftask->prc, args);
		get_size(fmt, &ftask->size);
	}
	validation_ftask(ftask);
	return (ret);
}

int			parse(char **fmt, t_out *out, va_list *args)
{
	int		ret;

	ret = 0;
	if ((out->res.len = ft_strclen(*fmt, '%')))
	{
		write(1, *fmt, out->res.len);
		(*fmt) += out->res.len;
	}
	if (**fmt == '%')
	{
		(*fmt)++;
		if (**fmt)
			ret = parse_ftask(fmt, &out->ftask, args);
	}
	return (ret);
}
