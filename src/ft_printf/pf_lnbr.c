/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_lnbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 11:37:37 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/28 05:13:39 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	clear_lnbr(t_lnbr *lnbr)
{
	ft_bzero(lnbr->vls, lnbr->len);
	lnbr->len = 0;
}

void	values_to_chars(char **data, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		(*data)[i++] += 48;
}

t_lnbr	set_lnbr(char *str)
{
	t_lnbr	res;
	ssize_t	i;
	ssize_t	i2;

	ft_bzero(res.vls, sizeof(res.vls));
	res.len = ft_strlen(str);
	i = 0;
	i2 = res.len - 1;
	while (i < res.len)
		res.vls[i++] = str[i2--] - 48;
	return (res);
}
