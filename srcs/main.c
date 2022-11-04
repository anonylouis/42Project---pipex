/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonylouis <anonylouis@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:27:46 by lcalvie           #+#    #+#             */
/*   Updated: 2022/01/17 22:40:43 by anonylouis       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	if (argc < 5)
		return (0);
	pipex = new_pipex(argc, argv);
	if (pipex == NULL)
		return (1);
	if (!fill_pipex(pipex, argc, argv, envp))
	{
		free_pipex(pipex);
		return (1);
	}
	if (!exec_all_cmds(argc, argv, envp, pipex))
	{
		free_pipex(pipex);
		return (1);
	}
	free_pipex(pipex);
	return (0);
}
