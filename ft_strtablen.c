/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtablen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:13:11 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/08 16:14:15 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strtablen(const char *str)
{
	size_t	len;

	len = 0;
	if (str && *str)
	{
		while (str && *str && !TABS(*str))
		{
			++str;
			++len;
		}
	}
	return (len);
}
