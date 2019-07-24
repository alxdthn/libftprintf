/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_emalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 22:20:41 by nalexand          #+#    #+#             */
/*   Updated: 2019/05/19 22:26:46 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_emalloc(size_t size)
{
	void	*src;

	if ((src = malloc(size)) && size)
		return (src);
	exit(EXIT_FAILURE);
}
