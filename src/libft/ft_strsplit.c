/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 03:15:30 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/13 19:12:12 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**res;

	if (!s || !(res = (char **)ft_memalloc(sizeof(char *)
	* (ft_wrdcount(s, c) + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		j = 0;
		s = ft_strcskp(s, c);
		if (!*s)
			break ;
		if (!(res[i] = (char *)ft_strnew(sizeof(char) * ft_strclen(s, c))))
		{
			ft_arraydel((void ***)&res);
			return (NULL);
		}
		while (*s != c && *s)
			res[i][j++] = *(char *)s++;
		i++;
	}
	return (res);
}
