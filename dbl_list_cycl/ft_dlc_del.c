/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlc_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:51:41 by ksharlen          #+#    #+#             */
/*   Updated: 2020/01/14 20:06:18 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dbl_list_cycl.h"

void	ft_dlc_del_list(t_dlc **beg)
{
	t_dlc	*res;
	t_dlc	*tmp;
	size_t	size;

	if (beg && *beg)
	{
		if ((*beg)->next)
		{
			size = ft_dlc_get_size(*beg);
			res = (*beg);
			while (size--)
			{
				tmp = res->next;
				ft_dlc_del(&res);
				res = tmp;
			}
		}
		else
			ft_dlc_del_elem(*beg);
		(*beg) = NULL;
	}
}

void	ft_dlc_del_elem(t_dlc *elem)
{
	if (elem)
	{
		if (elem->next && elem->next->next != elem)
		{
			elem->prev->next = elem->next;
			elem->next->prev = elem->prev;
		}
		else if (elem->next)
		{
			elem->next->next = NULL;
			elem->next->prev = NULL;
		}
		ft_dlc_del(&elem);
	}
}

void	ft_dlc_del_elem_f(t_dlc *elem, void (*del)())
{
	if (elem)
	{
		if (elem->next && elem->next->next != elem)
		{
			elem->prev->next = elem->next;
			elem->next->prev = elem->prev;
		}
		else if (elem->next)
		{
			elem->next->next = NULL;
			elem->next->prev = NULL;
		}
		del(&elem->data);
		ft_dlc_del(&elem);
	}
}

void	ft_dlc_del(t_dlc **elem)
{
	if (elem && *elem)
	{
		if ((*elem)->data)
			free((*elem)->data);
		free(*elem);
		(*elem) = NULL;
	}
}
