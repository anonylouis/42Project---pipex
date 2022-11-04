/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonylouis <anonylouis@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:15:53 by lcalvie           #+#    #+#             */
/*   Updated: 2022/01/17 22:44:33 by anonylouis       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipex	*new_pipex(int argc, char **argv)
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	if (pipex == NULL)
		return (0);
	pipex->cmd = NULL;
	if (argc >= 6 && strcmp("here_doc", argv[1]) == 0)
	{
		pipex->here_doc = 1;
		pipex->limiter = argv[2];
		pipex->outfile_flags = O_CREAT | O_APPEND | O_WRONLY;
	}
	else
	{
		pipex->here_doc = 0;
		pipex->outfile_flags = O_CREAT | O_TRUNC | O_WRONLY;
	}
	return (pipex);
}

static void	set_fd_infile(t_pipex *pipex, char **argv)
{
	if (pipex->here_doc == 0)
	{
		pipex->fd_infile = open(argv[1], O_RDONLY);
		if (pipex->fd_infile == -1)
		{
			ft_putstr_fd(strerror(errno), 2);
			ft_putstr_fd(": ", 2);
			ft_putstr_fd(argv[1], 2);
			ft_putchar_fd('\n', 2);
		}
	}
	else
		read_stdin(pipex);
}

int	fill_pipex(t_pipex *pipex, int argc, char **argv, char **envp)
{
	set_fd_infile(pipex, argv);
	pipex->cmd = malloc(sizeof(t_command));
	if (pipex->cmd == NULL)
		return (0);
	if (!new_command(argv[2 + pipex->here_doc], &(pipex->cmd), envp))
		return (0);
	if (pipe((pipex->cmd)->pipefds) == -1)
		perror("pipe");
	(pipex->cmd)->fd_in = pipex->fd_infile;
	(pipex->cmd)->fd_out = ((pipex->cmd)->pipefds)[1];
	pipex->fd_outfile = open(argv[argc - 1], pipex->outfile_flags, 0644);
	if (pipex->fd_outfile == -1)
		perror("open");
	return (1);
}

void	free_pipex(t_pipex *pipex)
{
	if (pipex)
	{
		free_command(pipex->cmd);
		free(pipex);
	}
}
