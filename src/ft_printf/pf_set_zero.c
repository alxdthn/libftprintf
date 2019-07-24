/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_set_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 02:05:55 by nalexand          #+#    #+#             */
/*   Updated: 2019/05/27 04:38:43 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_res(t_res *res, t_res *tmp, int *i, int *j)
{
	int		fill_count;

	*i = 0;
	*j = 0;
	if (ft_strchr("+- ", res->str[*j]))
		tmp->str[(*i)++] = res->str[(*j)++];
	else if (res->len > 1 && res->str[*j] == '0'
	&& (res->str[*j + 1] == 'x' || res->str[*j + 1] == 'X'))
	{
		*i = 2;
		*j = 2;
		ft_memcpy(tmp->str, res->str, 2);
	}
	fill_count = tmp->len - res->len;
	return (fill_count);
}

void		set_zero(t_res *res, int width)
{
	t_res	tmp;
	int		i;
	int		j;
	int		fill_count;

	if (res->len == -1)
		return ;
	tmp.str = NULL;
	tmp.len = width;
	if ((tmp.str = (char *)malloc(sizeof(char) * tmp.len)))
	{
		fill_count = check_res(res, &tmp, &i, &j);
		while (fill_count--)
			tmp.str[i++] = '0';
		while (j < res->len)
			tmp.str[i++] = res->str[j++];
	}
	else
		tmp.len = -1;
	ft_strdel(&res->str);
	*res = tmp;
}
