/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 02:15:34 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/25 15:43:32 by nalexand         ###   ########.fr       */
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
