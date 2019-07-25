/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:57:11 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/25 15:27:05 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# define MEM 100000000

int		main(void)
{
	char 	*str;
	size_t	i;

	str = (char *)malloc(MEM);
	//ft_memset(str, 255, MEM);
	//i = 0;
	//while (i < MEM)
	//	ft_printf("%#hhb ", str[i++]);
	//ft_printf("\n");
	ft_bzero(str, MEM);
	//i = 0;
	//while (i < MEM)
	//	ft_printf("%#hhb ", str[i++]);
	//ft_printf("\n");
	free(str);
}
