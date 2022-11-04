/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonylouis <anonylouis@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:37:16 by lcalvie           #+#    #+#             */
/*   Updated: 2022/01/17 00:23:01 by anonylouis       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "pipex.h"


int	print_err_malloc_failed(void)
{
	ft_putstr_fd("Malloc failed\n", 2);
	return (1);
}

static int	print_err_cmd_not_found(t_pipex *pipex)
{
	ft_putstr_fd("Command not found: ", 2);
	ft_putstr_fd((pipex->cmd)->path, 2);
	ft_putchar_fd('\n', 2);
	return (1);
}

static int	print_err_open_failed(char **argv)
{
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(argv[1], 2);
	ft_putchar_fd('\n', 2);
	return (errno);
}

static int	print_err_default(void)
{
	perror("");
	return (errno);
}

int	print_err(int err, t_pipex *pipex, char **argv)
{
	int	ret;

	if (err == 0)
		ret = print_err_malloc_failed();
	else if (err == -2 && !is_in_str((pipex->cmd)->path, '/'))
		ret = print_err_cmd_not_found(pipex);
	else if (err == -3)
		ret = print_err_open_failed(argv);
	else
		ret = print_err_default();
	free_pipex(pipex);
	return (ret);
}
*/