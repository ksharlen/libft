/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gap_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:18:19 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/08 01:14:31 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gap_buf.h"

void	print_buf_int(char *buf, size_t size_buf)
{
	for (size_t i = 0; i < size_buf; ++i)
		ft_printf("buf[%zd] = %d\n", i, buf[i]);
	ft_printf("\n");
}

void	print_buf_char(char *buf, size_t size_buf)
{
	for (size_t i = 0; i < size_buf; ++i)
		ft_printf("buf[%zd] = %c\n", i, buf[i]);
	ft_printf("\n");
}

void	print_stat_t_gapbuf(t_gapbuf *buf)
{
	ft_printf("SIZE_BUF: %zd\n", GAP_SIZE_BUF);
	ft_printf("slide: %zd\n", buf->slide);
	ft_printf("size_gap_buf: %zd\n", buf->size_gap_buf);
	ft_printf("gap_start: %zd\n", buf->gap_start);
	ft_printf("gap_end: %zd\n", buf->gap_end);
	ft_printf("len_string: %zd\n", buf->len_string);
	ft_printf("GAP_SLIDE: %zd\n", buf->slide);
	ft_printf("main_size_gap_buf: %zd\n", buf->main_size_gap_buf);
}

void	gap_print_buf(t_gapbuf *buf)
{
	size_t	size;

	if (BUF && LEN_STR)
	{
		if (GAP_START < LEN_STR + 1)
			size = SIZE_GAP_BUF + LEN_STR;
		else
			size = LEN_STR;
		write(STDOUT_FILENO, BUF, size);
	}
}
