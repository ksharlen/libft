/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gap_del_interface.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 22:39:53 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/06 22:44:43 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gap_buf.h"

static void		del_sym(t_gapbuf *buf, size_t del)
{
	int	ind;

	if (del <= LEN_STR)
	{
		ind = get_sym_ind_at_buf(buf, del);
		gap_move(buf, ind);
		BUF[GAP_END++ + 1] = '\0';
		LEN_STR--;
		SIZE_GAP_BUF++;
	}
}

void			gap_del_sym_before_slide(t_gapbuf *buf)
{
	if (LEN_STR)
	{
		if (GAP_SLIDE == LEN_STR)
		{
			BUF[LEN_STR + SIZE_GAP_BUF - 1] = '\0';
			--GAP_SLIDE;
			--LEN_STR;
		}
		else if (GAP_SLIDE)
			del_sym(buf, --GAP_SLIDE);
	}
}

void			gap_del_sym_on_slide(t_gapbuf *buf)
{
	if (LEN_STR && GAP_SLIDE < LEN_STR)
		del_sym(buf, GAP_SLIDE);
}

void			gap_clean_buf(t_gapbuf *buf)
{
	if (buf->buf)
		ft_bzero(buf->buf, sizeof(char) * GAP_SIZE_BUF);
	if (LEN_STR)
	{
		SIZE_GAP_BUF = buf->main_size_gap_buf;
		GAP_START = 0;
		GAP_END = SIZE_GAP_BUF - 1;
		GAP_SLIDE = 0;
		LEN_STR = 0;
	}
}
