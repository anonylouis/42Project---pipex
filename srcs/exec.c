/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonylouis <anonylouis@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:43:40 by lcalvie           #+#    #+#             */
/*   Updated: 2022/01/17 22:47:45 by anonylouis       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exec_cmd(t_pipex *pipex, char **envp, int last)
{
	int	child;

	child = fork();
	if (child == -1)
		return (perror("fork"));
	else if (child == 0)
	{
		if (!last && close((pipex->cmd)->pipefds[0]) == -1)
			perror("close");
		if ((pipex->cmd)->fd_in != -1)
			dup2((pipex->cmd)->fd_in, STDIN_FILENO);
		dup2((pipex->cmd)->fd_out, STDOUT_FILENO);
		if (((pipex->cmd)->fd_in != -1 && close((pipex->cmd)->fd_in))
			| close((pipex->cmd)->fd_out))
			perror("close");
		if ((pipex->cmd)->path != NULL && (pipex->cmd)->fd_in != -1)
			if (execve((pipex->cmd)->path, (pipex->cmd)->args, envp))
				perror("execve");
		exit(0);
	}
	if (((pipex->cmd)->fd_in != -1 && close((pipex->cmd)->fd_in))
		| close((pipex->cmd)->fd_out))
		perror("close");
}

static void	wait_childs(int n)
{
	while (--n >= 0)
		wait(NULL);
}

int	exec_all_cmds(int argc, char **argv, char **envp, t_pipex *pipex)
{
	int	i;

	i = 2 + pipex->here_doc;
	while (++i < argc - 1)
	{
		exec_cmd(pipex, envp, 0);
		free_tab(pipex->cmd->args);
		free(pipex->cmd->path);
		if (!new_command(argv[i], &(pipex->cmd), envp))
			return (0);
		(pipex->cmd)->fd_in = (pipex->cmd)->pipefds[0];
		if (i == argc - 2)
			(pipex->cmd)->fd_out = pipex->fd_outfile;
		else
		{
			if (pipe((pipex->cmd)->pipefds) == -1)
				perror("pipe");
			(pipex->cmd)->fd_out = (pipex->cmd)->pipefds[1];
		}
	}
	exec_cmd(pipex, envp, 1);
	wait_childs(argc - 3 - pipex->here_doc);
	return (1);
}
