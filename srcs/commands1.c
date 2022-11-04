/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonylouis <anonylouis@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 02:33:19 by lcalvie           #+#    #+#             */
/*   Updated: 2022/01/17 00:38:52 by anonylouis       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**copy_args(char **cmd_split, char *cmd_path)
{
	char	**cmd_args;
	int		i;

	i = 1;
	while (cmd_split[i])
		i++;
	cmd_args = malloc(sizeof(char *) * (i + 1));
	if (cmd_args == NULL)
		return (NULL);
	cmd_args[0] = ft_strdup(cmd_path);
	i = 0;
	while (cmd_split[++i])
		cmd_args[i] = ft_strdup(cmd_split[i]);
	cmd_args[i] = NULL;
	if (check_null(cmd_args, i))
		return (NULL);
	return (cmd_args);
}

int	new_command(char *cmd_name, t_command **cmd, char **envp)
{
	char	**cmd_split;

	(*cmd)->args = NULL;
	(*cmd)->path = NULL;
	cmd_split = ft_split(cmd_name, ' ');
	if (cmd_split == NULL)
		return (0);
	(*cmd)->path = find_cmd_path(cmd_split[0], envp);
	if ((*cmd)->path != NULL)
	{
		(*cmd)->args = copy_args(cmd_split, (*cmd)->path);
		free_tab(cmd_split);
		if ((*cmd)->args == NULL)
			return (0);
	}
	else
		free_tab(cmd_split);
	return (1);
}

void	free_command(t_command *cmd)
{
	if (cmd)
	{
		free_tab(cmd->args);
		free(cmd->path);
		free(cmd);
	}
}
