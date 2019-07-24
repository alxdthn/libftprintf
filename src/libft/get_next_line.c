/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 22:19:55 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/25 17:38:30 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			get_ofset(t_list **elem, size_t size)
{
	char			*tmp;

	if (!(tmp = (char *)ft_memalloc(SIZE * sizeof(char))))
		return (-1);
	ft_memcpy(tmp, ft_memchr(CONT, 10, size + 1) + 1, SIZE);
	ft_memdel(&CONT);
	if (!(CONT = ft_memalloc(SIZE * sizeof(char))))
		return (-1);
	ft_memcpy(CONT, tmp, SIZE);
	ft_memdel((void **)&tmp);
	return (1);
}

static int			make_new_line(char **line, t_list **elem, int ret)
{
	size_t			size;

	if (!(ft_memchr(CONT, 10, SIZE)) && !ret)
		size = SIZE;
	else
		size = (size_t)ft_memchr(CONT, 10, SIZE) - (size_t)CONT;
	if (!(SIZE) && !ret)
	{
		*line = NULL;
		ft_lstdel(elem, ft_lstclear);
		return (0);
	}
	if (!(*line = (char *)ft_strnew(sizeof(char) * size)))
		return (-1);
	ft_memcpy(*line, CONT, size);
	SIZE = SIZE - size - 1;
	if (SIZE + 1 == 0)
	{
		ft_lstdel(elem, ft_lstclear);
		return (1);
	}
	if (SIZE)
		return (get_ofset(elem, size));
	ft_lstdel(elem, ft_lstclear);
	return (1);
}

int					get_new_line(const int fd, char **line, t_list **elem)
{
	int				ret;
	char			*res;
	char			buf[BUFF_SIZE];

	while (!(ft_memchr(CONT, 10, SIZE)))
	{
		if (!(ret = read(fd, buf, BUFF_SIZE)))
			break ;
		if (!(res = (char *)ft_memalloc((SIZE + ret) * sizeof(char))))
			return (-1);
		ft_memcpy(res, CONT, SIZE);
		ft_memcpy(res + SIZE, buf, ret);
		SIZE += ret;
		ft_memdel(&CONT);
		if (!(CONT = ft_memalloc(sizeof(char) * SIZE)))
			return (-1);
		ft_memcpy(CONT, res, SIZE);
		ft_memdel((void **)&res);
	}
	return (make_new_line(line, elem, ret));
}

int					ft_lstfind(t_list **lst, int fd, char **line)
{
	t_list			*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (tmp->content_size == (size_t)fd)
		{
			if (!tmp->content)
				tmp->content = ft_lstnew(NULL, 0);
			return (get_new_line(fd, line, (t_list **)&tmp->content));
		}
		tmp = tmp->next;
	}
	if (!(tmp = ft_lstnew(NULL, 0)))
		return (-1);
	tmp->content_size = fd;
	ft_lstadd(lst, tmp);
	return (ft_lstfind(lst, fd, line));
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	char			buf[0];
	int				ret;

	if (fd < 0 || read(fd, buf, 0) < 0 || line == NULL)
		return (-1);
	*line = NULL;
	if (!lst)
	{
		if (!(lst = ft_lstnew(NULL, 0)))
			return (-1);
		lst->content_size = fd;
	}
	if (!(ret = ft_lstfind(&lst, fd, line)))
	{
		ft_memdel((void **)&lst);
		return (ret);
	}
	return (ret);
}
