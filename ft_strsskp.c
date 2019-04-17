/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strskp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 14:39:35 by nalexand          #+#    #+#             */
/*   Updated: 2019/04/12 00:25:01 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsskp(const char *str, char *c)
{
	int i;
	int match;

	i = 0;
	match = 0;
	while (*str)
	{
		while (c[i])
		{
			if (*str == c[i])
				match++;
			if (match)
				break ;
			i++;
		}
		if (match)
		{
			str++;
			i = 0;
			match = 0;
		}
		else
			return ((char *)str);
	}
	return ((char *)str);
}
