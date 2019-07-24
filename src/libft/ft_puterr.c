/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 00:27:43 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/16 16:26:56 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_puterr(int ret, char *message)
{
	size_t	i;

	if (message && *message)
	{
		i = 0;
		while (message[i])
			i++;
		write(2, message, i);
		write(2, "\n", 1);
	}
	return (ret);
}
