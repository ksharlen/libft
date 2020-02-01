/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gap_common.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 18:23:23 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/01 16:37:50 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gap_buf.h"

void	get_new_gapbuf(t_gapbuf *buf, size_t len_get_new_gapbuf)
{
	if (!len_get_new_gapbuf)
		len_get_new_gapbuf = buf->main_size_gap_buf;
	if (len_get_new_gapbuf >= (GAP_SIZE_BUF - LEN_STR))
		len_get_new_gapbuf = (GAP_SIZE_BUF - LEN_STR);
	GAP_START = LEN_STR + 1;
	GAP_END = GAP_START + len_get_new_gapbuf - 1;
	SIZE_GAP_BUF = len_get_new_gapbuf;
}

int		get_sym_ind_at_buf(t_gapbuf *buf, size_t pos_sym)
{
	size_t	ind;
	size_t	sym;

	if (pos_sym <= LEN_STR)
	{
		ind = 0;
		sym = 0;
		while(ind < (LEN_STR + SIZE_GAP_BUF) && sym != pos_sym)
		{
			if (BUF[ind++] != '\0')
				++sym;
		}
		return (ind);
	}
	return (-1);
}

void	delete_gapbuf(t_gapbuf *buf)
{
	if (SIZE_GAP_BUF && GAP_START < LEN_STR)
	{
		while (GAP_START != (SIZE_GAP_BUF + LEN_STR + 1))
		{
			BUF[GAP_START++] = BUF[++GAP_END];
			BUF[GAP_END] = '\0';
		}
	}
	GAP_START = 0;
	GAP_END = 0;
	SIZE_GAP_BUF = 0;
}

void	die_gap(const char *s)
{
	write(STDERR_FILENO, s, ft_strlen(s));
	exit(EXIT_FAILURE);
}
