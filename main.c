/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:22:11 by ksharlen          #+#    #+#             */
/*   Updated: 2019/11/11 18:24:30 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		main(int argc, char **argv)
{
	char	*hello = "hello ";
	char	str[20] = {0};

	if (argc == 2)
	{
		ft_strcpy(str, hello);
		ft_strcat(str, argv[1]);
		ft_printf("%s\n", str);
	}
	return (0);
}
