/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlncpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:44:20 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/04 15:47:49 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlncpy(char *dst, char *src, size_t n)
{
	char	*p_dst;
	size_t	len_dst;
	size_t	len_src;

	p_dst = NULL;
	if (dst && src)
	{
		len_dst = sizeof(dst) / sizeof(dst[0]);
		len_src = ft_strlen(src);
		if (len_dst < len_src && (n <= len_src))
		{
			p_dst = dst;
			ft_strncpy(dst, src, n);
		}
	}
	return (p_dst);
}
