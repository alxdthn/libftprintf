/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 20:47:50 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/20 20:54:12 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t size)
{
	char	*res;
	size_t	i;
	size_t	len;

	res = NULL;
	if (!(len = ft_strlen(s1)))
		return (res);
	len = (size > len) ? len : size;
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (res);
	i = 0;
	while (i < len)
	{
		res[i] = s1[i];
		++i;
	}
	res[i] = '\0';
	return (res);
}
