/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 23:48:17 by nalexand          #+#    #+#             */
/*   Updated: 2019/05/27 04:40:14 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(void *data, size_t size)
{
	void	*res;
	size_t	i;

	i = 0;
	if ((res = malloc(sizeof(char) * size)))
	{
		while (i < size)
		{
			((char *)res)[i] = ((char *)data)[i];
			i++;
		}
		return (res);
	}
	return (NULL);
}
