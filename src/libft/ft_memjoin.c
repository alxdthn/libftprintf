/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 21:46:06 by nalexand          #+#    #+#             */
/*   Updated: 2019/05/29 18:25:29 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memjoin(void *dst, void *src, size_t s_dst, size_t s_src)
{
	void	*res;

	res = NULL;
	if (!(res = ft_memalloc((s_dst + s_src) * sizeof(char))))
		return (NULL);
	if (s_dst)
		ft_memcpy(res, dst, s_dst);
	ft_memcpy(res + s_dst, src, s_src);
	return (res);
}
