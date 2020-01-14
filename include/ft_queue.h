/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:30:40 by ksharlen          #+#    #+#             */
/*   Updated: 2020/01/14 14:35:38 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QUEUE_H
# define FT_QUEUE_H

# include <stdlib.h>
# include <sys/types.h>
# include <limits.h>

# include "libft.h"

typedef struct	s_queue
{
	struct s_list	*beg_queue;
	struct s_list	*end_queue;
}				t_queue;

//push
//pop

#endif
