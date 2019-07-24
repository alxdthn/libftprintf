/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 09:44:50 by nalexand          #+#    #+#             */
/*   Updated: 2019/04/17 13:37:54 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;

	if (lst)
	{
		if (!(tmp = f(lst)))
			return (NULL);
		tmp->next = ft_lstmap(lst->next, f);
		return (tmp);
	}
	return (NULL);
}
