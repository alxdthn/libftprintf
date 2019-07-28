/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 02:18:38 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/29 02:22:21 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	write_from_list(t_gnl *gnl)
{
	t_list	*tmp;
	t_list	*tmp2;
	size_t	ofset;

	ofset = 0;
	if (gnl->cur_fd->buf->next)
	{
		tmp = gnl->cur_fd->buf->next;
		while (tmp)
		{
			tmp2 = tmp->next;
			ft_memcpy(*gnl->line + ofset, tmp->content, tmp->content_size);
			ofset += tmp->content_size;
			ft_lstdelone(&tmp, ft_lstclear);
			tmp = tmp2;
		}
	}
	return (ofset);
}

void			write_line(t_gnl *gnl)
{
	char	*str_tmp;
	size_t	size;
	size_t	ofset;

	ofset = write_from_list(gnl);
	str_tmp = ft_memchr(CONT, '\n', SIZE);
	size = (str_tmp) ? (size_t)str_tmp - (size_t)CONT : SIZE;
	ft_memcpy(*gnl->line + ofset, CONT, size);
	if (str_tmp && SIZE - size - 1)
	{
		str_tmp = ft_memdup(str_tmp + 1, SIZE - size - 1);
		ft_memdel(&CONT);
		CONT = str_tmp;
		SIZE -= size + 1;
	}
	else
		ft_lstdelone(&gnl->cur_fd->buf, ft_lstclear);
}
