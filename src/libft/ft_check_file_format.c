/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 06:06:56 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/13 06:35:33 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check_file_format(char *file, char *format)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(format);
	while (file[i])
		i++;
	while (j)
	{
		if (file[i] != format[j])
			return (1);
		j--;
		i--;
	}
	return (0);
}
