/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:46:28 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/15 19:13:43 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char *const g_sys_errors[] = {
	"open_error",
	"close_error",
	"read_error",
	"opendir_error",
	"closedir_error",
	"readdir_error",
	"fork_error",
	"wait_error",
	"signal_error",
	"time_error",
	"ctime_error",
	"waitpid_error",
	"kill_error",
	"getcwd_error",
	"malloc_error",
	"chdir_error",
	"stat_error",
	"fstat_error",
	"lstat_error",
	"getpwduid_error"
};

void	ft_err_str(t_error nerror, const char *add_text)
{
	if (add_text && *add_text)
		ft_printf("%v%s: %s\n", STDERR_FILENO, add_text, g_sys_errors[nerror]);
	else
		ft_printf("%v%s\n", STDERR_FILENO, g_sys_errors[nerror]);
}

void	ft_err_exit(t_error nerror, const char *add_text)
{
	ft_err_str(nerror, add_text);
	exit(EXIT_FAILURE);
}
