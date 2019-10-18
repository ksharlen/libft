/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 22:36:12 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/17 22:55:46 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		main(int argc, char **argv)
{
	char		*str[3] = {"0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0", "0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0", "0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0"};
	char		*p_str;
	int			h;
	unsigned 	c;
	int			i;
	int			j;

	i = 0;
	while (i < 3)
	{
		p_str = str[i];
		j = 0;
		while (p_str && *p_str && j < 19)
		{
			h = ft_atoi_base_ptr(p_str, 10, &p_str);
			printf("%d|", h);
			p_str++;
			c = ft_atoi_base_ptr(p_str, 16, &p_str);
			printf("%u	", c);
			++j;
		}
		printf("\n");
		++i;
	}
	return (0);
}