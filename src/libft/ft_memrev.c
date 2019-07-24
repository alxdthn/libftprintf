/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 11:26:23 by nalexand          #+#    #+#             */
/*   Updated: 2019/05/12 11:26:36 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrev(void *data, size_t size)
{
	void	*res;
	size_t	i;
	size_t	i2;

	if (!data || !size ||
		!(res = ft_memalloc(sizeof(char) * size)))
		return (NULL);
	i = 0;
	i2 = size - 1;
	while (i < size)
		((unsigned char *)res)[i++] = ((unsigned char *)data)[i2--];
	ft_memdel(&data);
	return (res);
}
