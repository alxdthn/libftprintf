/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 18:41:44 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/25 17:38:52 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	unicode_len(wchar_t *u_str, int count, int prc)
{
	size_t	res;
	char	size;

	res = 0;
	while (*u_str && count && prc)
	{
		if (*u_str >= 65536)
			size = 4;
		else if (*u_str >= 2048)
			size = 3;
		else if (*u_str >= 128)
			size = 2;
		else
			size = 1;
		if (prc > 0 && (int)(prc - size) < 0)
			break ;
		res += size;
		prc -= size;
		u_str++;
		if (count > 0)
			count--;
	}
	return (res);
}

char	*get_uchar(char *buf, int uchar, int size)
{
	t_unic	uni;

	uni.bits = uchar;
	if (size == 1)
		buf[0] = (char)uchar;
	else if (size == 2)
	{
		buf[0] = uni.parts.b | 0xC0;
		buf[1] = uni.parts.a | 0x80;
	}
	else if (size == 3)
	{
		buf[0] = uni.parts.c | 0xE0;
		buf[1] = uni.parts.b | 0x80;
		buf[2] = uni.parts.a | 0x80;
	}
	else if (size == 4)
	{
		buf[0] = uni.parts.d | 0xF0;
		buf[1] = uni.parts.c | 0x80;
		buf[2] = uni.parts.b | 0x80;
		buf[3] = uni.parts.a | 0x80;
	}
	return (buf);
}
