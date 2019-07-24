/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 02:43:50 by nalexand          #+#    #+#             */
/*   Updated: 2019/05/10 02:44:10 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*tmp;
	size_t	size;
	size_t	start;

	if (!(size = ft_strlen(str)) ||
		!(tmp = ft_strnew(size)))
	{
		ft_strdel(&str);
		return (NULL);
	}
	start = 0;
	while (size--)
		tmp[start++] = str[size];
	size = 0;
	while (start)
	{
		str[size] = tmp[size];
		size++;
		start--;
	}
	ft_strdel(&tmp);
	return (str);
}
