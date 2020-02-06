/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gap_interface.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 22:26:04 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/06 22:25:05 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gap_buf.h"

static void		fill_str_skip_gap(t_gapbuf *buf, char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < LEN_STR)
	{
		if (BUF[j])
		{
			str[i] = BUF[j];
			++i;
		}
		++j;
	}
}

char			*gap_get_buf(t_gapbuf *buf)
{
	char	*str;

	str = NULL;
	if (LEN_STR)
	{
		str = ft_strnew(LEN_STR);
		if (!str)
			die_gap("gap_get_buf: malloc_error");
		if (!GAP_START)
			ft_memcpy(str, &BUF[GAP_END + 1], LEN_STR);
		else if (GAP_START == (LEN_STR + 1))
			ft_memcpy(str, BUF, LEN_STR);
		else
			fill_str_skip_gap(buf, str);
		str[LEN_STR] = '\0';
	}
	return (str);
}

void			gap_slide_left(t_gapbuf *buf)
{
	if (GAP_SLIDE)
		--GAP_SLIDE;
}

void	gap_slide_right(t_gapbuf *buf)
{
	if (GAP_SLIDE < (LEN_STR))
		++GAP_SLIDE;
}

void			gap_init(t_gapbuf *buf, size_t size_buf,
	size_t size_gap)
{
	if (buf && size_buf && size_gap)
	{
		BUF = (char *)ft_memalloc(sizeof(char) *
			(size_buf + size_gap));
		if (!BUF)
			die_gap("gap_init: malloc_error");
		GAP_SIZE_BUF = size_buf + size_gap;
		ft_bzero(BUF, sizeof(char) * GAP_SIZE_BUF);
		SIZE_GAP_BUF = size_gap;
		buf->main_size_gap_buf = size_gap;
		GAP_START = 0;
		GAP_END = SIZE_GAP_BUF - 1;
		GAP_SLIDE = 0;
		LEN_STR = 0;
	}
	else
		die_gap("size_buf || size_gap = 0");
}
