/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:22:52 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/06 18:30:39 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace(char *in, char *from)
{
	size_t	len_in;
	size_t	len_from;
	char	*dst;

	dst = NULL;
	if (in && from)
	{
		len_in = ft_strlen(in);
		len_from = ft_strlen(from);
		CHK_NULL_PTR(dst = ft_strnew(len_in + len_from), E_MALLOC, "libft");
		ft_strcat(dst, in);
		ft_strcat(dst, from);
		ft_strdel(&in);
		ft_strdel(&from);
	}
	return (dst);
}
