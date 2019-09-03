/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 17:11:43 by ksharlen          #+#    #+#             */
/*   Updated: 2019/08/27 17:17:16 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_setncat(char *str, int sym, size_t size)
{
	register size_t i;
	char *ret;

	i = 0;
	ret = str;
	while (*str)
		++str;
	while (i < size)
	{
		str[i] = sym;
		++i;
	}
	return (str);
}