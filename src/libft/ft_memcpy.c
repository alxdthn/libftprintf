/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:39:38 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/29 02:26:30 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == src)
		return (dst);
	i = 0;
	while (i < n / 8)
	{
		((unsigned long *)dst)[i] = ((unsigned long *)src)[i];
		i++;
	}
	i *= 8;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned long	set;
	size_t			i;

	i = 0;
	set = 0;
	while (i < n / 8)
		((unsigned long *)s)[i++] = set;
	i *= 8;
	while (i < n)
		((unsigned char *)s)[i++] = '\0';
}