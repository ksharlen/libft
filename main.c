/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 01:07:03 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/16 01:27:47 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		main(int argc, char **argv)
{
	int result;

	if (argc == 3)
	{
		result = ft_atoi_base(argv[1], ft_atoi(argv[2]));
		printf("result: %d\n", result);
	}
	return (0);
}