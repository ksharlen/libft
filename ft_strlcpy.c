/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:25:51 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/04 15:37:19 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlcpy(char *dst, char *src)
{
	char	*p_dst;
	size_t	len_dst;
	size_t	len_src;

	p_dst = NULL;
	if (dst && src && *src)
	{
		len_dst = sizeof(dst) / sizeof(dst[0]);
		len_src = ft_strlen(src);
		if (len_dst < len_src)
		{
			p_dst = dst;
			ft_strcpy(dst, src);
		}
	}
	return (p_dst);
}
