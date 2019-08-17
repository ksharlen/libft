/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasecmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 12:16:26 by ksharlen          #+#    #+#             */
/*   Updated: 2019/08/17 12:28:00 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcasecmp(const char *s1, const char *s2)
{
	const unsigned char *p1;
	const unsigned char *p2;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	int result;

	while ((result = ft_tolower(*p1) - ft_tolower(*p2++)) == 0)
		if (*p1++ == '\0')
			break ;
	return (result);
}
