/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 02:35:00 by nalexand          #+#    #+#             */
/*   Updated: 2019/04/12 00:25:01 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	int		i2;
	int		max;
	size_t	src_len;
	size_t	dst_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	max = (int)size - (int)dst_len - 1;
	i = 0;
	i2 = 0;
	if (max < 0)
		return (size + src_len);
	while (dst[i])
		i++;
	while (src[i2] && max--)
		dst[i++] = src[i2++];
	dst[i] = '\0';
	return (src_len + dst_len);
}
