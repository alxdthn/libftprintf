/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:33:33 by nalexand          #+#    #+#             */
/*   Updated: 2019/04/12 00:25:01 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skip_white(char const *s, int i)
{
	if (!i)
	{
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		return (i);
	}
	if (i)
	{
		while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || !s[i]) && i)
			i--;
		return (i);
	}
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*res;
	int		mem;
	int		len;
	int		start;
	int		end;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	start = skip_white(s, 0);
	if (start == len)
	{
		res = ft_strnew(1);
		return (res);
	}
	end = skip_white(s, len);
	mem = len - (size_t)start - (len - (size_t)end) + 1;
	if (!(res = (char *)ft_strnew(sizeof(char) * mem)))
		return (NULL);
	return (ft_strncpy(res, (s + start), mem));
}
