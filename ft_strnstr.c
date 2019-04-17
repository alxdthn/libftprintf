/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 06:38:58 by nalexand          #+#    #+#             */
/*   Updated: 2019/04/12 00:25:01 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *str2, size_t len)
{
	int i;
	int size;

	i = 0;
	if (!(*str2) || str == str2)
		return ((char *)str);
	while (*str && len)
	{
		size = (int)len;
		while (str[i] && str2[i] && str[i] == str2[i] && size)
		{
			i++;
			size--;
		}
		if (!str2[i])
			return ((char *)str);
		size = len;
		i = 0;
		len--;
		str++;
	}
	return (NULL);
}
