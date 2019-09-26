/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 22:46:15 by ksharlen          #+#    #+#             */
/*   Updated: 2019/09/25 23:10:11 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdel_split(char **del)
{
	size_t i;

	i = 0;
	if (del && *del)
	{
		while (*del)
		{
			ft_strdel(&del[i]);
			++i;
			del++;
		}
	}
}
