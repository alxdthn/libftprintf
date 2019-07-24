/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 23:18:21 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/20 20:47:36 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	i;
	size_t	len;

	res = NULL;
	if (!(len = ft_strlen(s1))
	|| !(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (res);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		++i;
	}
	res[i] = '\0';
	return (res);
}
