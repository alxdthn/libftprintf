/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:04:22 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/21 19:46:19 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len;
	int		i;

	len = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	if (!(res = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	i = 0;
	if (s1)
		while (*s1)
			res[i++] = *(char *)(s1++);
	if (s2)
		while (*s2)
			res[i++] = *(char *)(s2++);
	res[i] = '\0';
	return (res);
}
