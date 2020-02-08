/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nsym.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:25:52 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/08 19:19:30 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_nsym(int fd, char sym, size_t n)
{
	void	*str;

	if (n)
	{
		str = ft_memalloc(n);
		ft_memset(str, sym, n);
		write(fd, str, n);
		ft_memdel(&str);
	}
}
