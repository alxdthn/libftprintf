/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_fun.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihail <mihail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 01:38:31 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/23 17:40:49 by mihail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	fun_flag_rus(void)
{
	char	rus[RUS_SQR + 1];
	char	*tmp;
	int		ofset;

	ft_memset(rus, ' ', sizeof(rus));
	ofset = 0;
	while (ofset < RUS_SQR)
	{
		ft_memcpy(rus + (ofset += RUS_WIDTH - 5), "\033[0m\n", 5);
		ofset += 5;
	}
	while (ofset)
	{
		if (ofset <= RUS_SQR / 3)
			tmp = "\033[0;47m";
		else if (ofset <= RUS_SQR / 3 * 2)
			tmp = "\033[0;44m";
		else
			tmp = "\033[0;41m";
		ft_memcpy(rus + (ofset -= RUS_WIDTH), tmp, 7);
	}
	rus[RUS_SQR] = '\0';
	write(1, rus, RUS_SQR);
	return (RUS_SQR);
}

static void	usa_set_top(char usa[1088], int *ofset)
{
	t_res	l1;
	t_res	l2;
	t_res	endl;

	l1.str = "\033[37;44m ★   ★   ★   ★   ★   ★ \033[37;41m";
	l1.len = ft_strlen(l1.str);
	l2.str = "\033[37;44m   ★   ★   ★   ★   ★   \033[37;47m";
	l2.len = ft_strlen(l2.str);
	endl.str = "                         \033[0m\n";
	endl.len = ft_strlen(endl.str);
	while (*ofset >= 0)
	{
		ft_memcpy(usa + *ofset, l1.str, l1.len);
		(*ofset) += l1.len;
		ft_memcpy(usa + *ofset, endl.str, endl.len);
		(*ofset) += endl.len;
		if (*ofset > 700)
			break ;
		ft_memcpy(usa + *ofset, l2.str, l2.len);
		(*ofset) += l2.len;
		ft_memcpy(usa + *ofset, endl.str, endl.len);
		(*ofset) += endl.len;
	}
}

static int	fun_flag_usa(void)
{
	char	usa[1088];
	int		ofset;

	ofset = 0;
	usa[0] = 'a';
	usa_set_top(usa, &ofset);
	ft_memset(usa + ofset, ' ', sizeof(usa) - ofset);
	while (ofset < 1000)
	{
		ft_memcpy(usa + ofset, "\033[37;47m", 8);
		ofset += 56;
		ft_memcpy(usa + ofset, "\033[0m\n", 5);
		ofset += 5;
		ft_memcpy(usa + ofset, "\033[37;41m", 8);
		ofset += 56;
		ft_memcpy(usa + ofset, "\033[0m\n", 5);
		ofset += 5;
	}
	usa[ofset] = '\0';
	write(1, usa, ofset);
	return (ofset);
}

static int	fun_ems(va_list *args)
{
	t_ems		uni;
	int			ret;

	uni.ldbl = va_arg(*args, long double);
	(*args)[0].overflow_arg_area -= 16;
	ret = print_ldbl_ems(uni, 1);
	return (ret);
}

int			solve_fun(char *clr, va_list *args)
{
	if (ft_strequ(clr, RUS))
		return (fun_flag_rus());
	else if (ft_strequ(clr, USA))
		return (fun_flag_usa());
	else if (ft_strequ(clr, EMS))
		return (fun_ems(args));
	return (0);
}
