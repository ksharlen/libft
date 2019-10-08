/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:55:55 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/08 16:00:15 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtabchr(const char *str, const char sym)
{
	char	*p_str;

	p_str = NULL;
	if (str && *str)
	{
		while (str && *str && !TABS(*str))
		{
			if (*str == sym)
			{
				p_str = (char *)str;
				break ;
			}
			++str;
		}
	}
	return (p_str);
}
