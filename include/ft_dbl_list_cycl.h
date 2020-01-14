/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_list_cycl.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:03:29 by ksharlen          #+#    #+#             */
/*   Updated: 2020/01/14 19:40:35 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DBL_LIST_CYCL_H
# define FT_DBL_LIST_CYCL_H

# include <sys/types.h>
# include <stdlib.h>

# include "libft.h"

typedef struct 	s_dbl_list_cycl
{
	struct s_dbl_list_cycl	*next;
	struct s_dbl_list_cycl	*prev;
	void					*data;
	size_t					size_data;
}				t_dlc;

/*
**DONE
*/
t_dlc	*ft_dlc_new(void *data, size_t size_data);
void	ft_dlc_add_beg(t_dlc **beg, void *data, size_t size_data);
void	ft_dlc_add_end(t_dlc **beg, void *data, size_t size_data);
t_dlc	*ft_dlc_get_beg(t_dlc **beg);
t_dlc	*ft_dlc_get_end(t_dlc **beg);

/*
**beg does not = NULL
*/
void	ft_dlc_del_elem(t_dlc *elem);
void	ft_dlc_del(t_dlc **elem);

/*
**DEV
*/
void	ft_dlc_del_list(t_dlc **beg);
size_t	ft_dlc_get_size(t_dlc *beg);

#endif
