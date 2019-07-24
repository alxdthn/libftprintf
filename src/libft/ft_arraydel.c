/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 06:02:38 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/19 20:07:49 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arraydel(void ***array)
{
	int i;

	if (array && *array)
	{
		i = 0;
		while ((*array)[i])
		{
			ft_memdel(&((*array)[i]));
			i++;
		}
		ft_memdel((void **)array);
	}
}
