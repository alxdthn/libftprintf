/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 21:48:03 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/21 19:21:25 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_read_to_str(int fd, char **str, size_t b_size)
{
	char	*buf;
	char	*tmp;
	ssize_t	size;
	int		ret;

	if (!(buf = (char *)malloc(sizeof(char) * (b_size + 1))))
		return (-1);
	size = 0;
	*str = NULL;
	while ((ret = read(fd, buf, b_size)))
	{
		buf[ret] = '\0';
		if (!(tmp = ft_strjoin(*str, buf)))
			return (-1);
		ft_strdel(str);
		*str = tmp;
		size += ret;
	}
	ft_strdel(&buf);
	return (size);
}
