/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strscat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:38:48 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/08 18:02:20 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strscat(char *dst, char *src, const char sym)
{
	char	*p_dst;
	size_t	before_sym;

	p_dst = NULL;
	if (dst && src && *src && sym >= 0)
	{
		before_sym = ft_strnlen(src, sym);
		p_dst = src;
		while (*dst)
			++dst;
		ft_strncpy(dst, src, before_sym);
		p_dst += (before_sym + 1);
	}
	return (p_dst);
}
