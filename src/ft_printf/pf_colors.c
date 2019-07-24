/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihail <mihail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 08:25:53 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/23 17:38:50 by mihail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	get_bonus(char **fmt, char **clr)
{
	if ((ft_strnstr(*fmt, "{rus}", 5)))
		*clr = RUS;
	else if ((ft_strnstr(*fmt, "{usa}", 5)))
		*clr = USA;
	else if ((ft_strnstr(*fmt, "{ems}", 5)))
		*clr = EMS;
}

void		get_color(char **fmt, char **clr)
{
	if ((ft_strnstr(*fmt, "{eoc}", 5)))
		*clr = EOC;
	else if ((ft_strnstr(*fmt, "{blc}", 5)))
		*clr = BLC;
	else if ((ft_strnstr(*fmt, "{red}", 5)))
		*clr = RED;
	else if ((ft_strnstr(*fmt, "{gre}", 5)))
		*clr = GRE;
	else if ((ft_strnstr(*fmt, "{yel}", 5)))
		*clr = YEL;
	else if ((ft_strnstr(*fmt, "{blu}", 5)))
		*clr = BLU;
	else if ((ft_strnstr(*fmt, "{mag}", 5)))
		*clr = MAG;
	else if ((ft_strnstr(*fmt, "{cyn}", 5)))
		*clr = CYN;
	else if ((ft_strnstr(*fmt, "{whi}", 5)))
		*clr = WHI;
	else
		get_bonus(fmt, clr);
	if (*clr)
		*fmt += 5;
}

int			solve_color(char *clr, va_list *args)
{
	int		ret;

	ret = 0;
	if (clr)
	{
		if (ft_strequ(clr, RUS) || ft_strequ(clr, USA)
		|| ft_strequ(clr, EMS))
			ret = solve_fun(clr, args);
		else
			write(1, clr, ft_strlen(clr));
	}
	return (ret);
}

int			parse_color(char **fmt, t_ftask *ftask, va_list *args)
{
	int		ret;

	ret = 0;
	get_color(fmt, &ftask->clr);
	if (ftask->clr)
	{
		ret += solve_color(ftask->clr, args);
		if (!find_type(*fmt))
		{
			ftask->clr = NULL;
			return (ret);
		}
	}
	else
	{
		ftask->type = '{';
		(*fmt)++;
	}
	return (ret);
}
