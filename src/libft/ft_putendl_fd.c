/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 00:47:01 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/16 16:21:23 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	size_t	i;

	if (fd < 0)
		return ;
	if (s && *s)
	{
		i = 0;
		while (s[i])
			i++;
		write(fd, s, i);
	}
	write(fd, "\n", 1);
}
