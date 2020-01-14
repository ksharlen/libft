/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:53:15 by ksharlen          #+#    #+#             */
/*   Updated: 2020/01/14 14:57:29 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"

void	ft_queue_insert(t_queue *queue, void *data, size_t content_size)
{
	t_list	*new;

	if (queue && data && content_size)
	{
		new = ft_lstnew(data, content_size);
		if (queue->beg_queue)
		{
			new->next = queue->beg_queue;
			queue->beg_queue = new;
		}
		else
		{
			queue->beg_queue = new;
			queue->end_queue = new;
		}
	}
}
