/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 05:41:28 by nalexand          #+#    #+#             */
/*   Updated: 2019/04/12 00:25:01 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *str2)
{
	int i;
	int i2;

	i = 0;
	i2 = 0;
	if (str == str2)
		return ((char *)str);
	while (*str)
	{
		while (str[i] && str2[i2] && str[i] == str2[i2])
		{
			i++;
			i2++;
		}
		if (!str2[i2])
			return ((char *)str);
		else
		{
			i = 0;
			i2 = 0;
		}
		str++;
	}
	return (NULL);
}
