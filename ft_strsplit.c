/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 03:15:30 by nalexand          #+#    #+#             */
/*   Updated: 2019/04/12 00:25:01 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		i2;
	char	**res;

	if (!s)
		return (NULL);
	if (!(res = (char **)ft_memalloc(sizeof(char *)
		* ft_wrdcount(s, c) + sizeof(char *))))
		return (NULL);
	i = 0;
	while (*s)
	{
		i2 = 0;
		s = ft_strcskp(s, c);
		if (!*s)
			break ;
		if (!(res[i] = (char *)ft_strnew(sizeof(char) * ft_strclen(s, c))))
			return (NULL);
		while (*s != c && *s)
			res[i][i2++] = *(char *)s++;
		i++;
	}
	return (res);
}
