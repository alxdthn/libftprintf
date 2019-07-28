/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 02:05:50 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/29 02:19:17 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# define CONT gnl->cur_fd->buf->content
# define SIZE gnl->cur_fd->buf->content_size
# define BUFF_SIZE 666

typedef struct		s_fd
{
	t_list			*buf;
	int				fd;
}					t_fd;

typedef struct		s_gnl
{
	char			buf[BUFF_SIZE];
	t_list			*fd_lst;
	t_fd			*cur_fd;
	ssize_t			ret;
	ssize_t			read_ret;
	int				fd;
	char			**line;
}					t_gnl;

void				clear_fd_node(t_gnl *gnl);
void				fd_lst_clear(void *content, size_t size);
void				write_line(t_gnl *gnl);

#endif
