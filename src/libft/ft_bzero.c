/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihail <mihail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 02:15:34 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/25 02:59:12 by mihail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
