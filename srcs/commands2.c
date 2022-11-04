/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonylouis <anonylouis@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:27:17 by lcalvie           #+#    #+#             */
/*   Updated: 2022/01/17 00:37:48 by anonylouis       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**find_path(char **envp)
{
	int		i;
	char	*var_path;

	var_path = NULL;
	i = -1;
	while (!var_path && envp[++i])
	{
		if (!ft_memcmp("PATH=", envp[i], 5))
			var_path = envp[i];
	}
	if (var_path == NULL)
		return (NULL);
	return (ft_split(envp[i] + 5, ':'));
}

static char	*find_cmd_path_with_name(char *cmd_name)
{
	if (access(cmd_name, X_OK) == 0)
		return (ft_strdup(cmd_name));
	return (NULL);
}

static char	*find_cmd_absolute_path(char *cmd_name, char **envp)
{
	char	**path;
	char	*cmd_path;
	int		i;

	cmd_path = NULL;
	if (cmd_name && cmd_name[0] != '\0')
	{
		path = find_path(envp);
		if (path == NULL)
			return (NULL);
		cmd_name = ft_strjoin("/", cmd_name);
		i = -1;
		while (cmd_name && !cmd_path && path[++i])
		{
			cmd_path = ft_strjoin(path[i], cmd_name);
			if (cmd_path && access(cmd_path, X_OK))
			{
				free(cmd_path);
				cmd_path = NULL;
			}
		}
		free(cmd_name);
		free_tab(path);
	}
	return (cmd_path);
}

char	*find_cmd_path(char *cmd_name, char **envp)
{
	char	*cmd_path;

	if (is_in_str(cmd_name, '/'))
	{
		cmd_path = find_cmd_path_with_name(cmd_name);
		if (cmd_path == NULL)
		{
			ft_putstr_fd(strerror(errno), 2);
			ft_putstr_fd(": ", 2);
			ft_putstr_fd(cmd_name, 2);
			ft_putchar_fd('\n', 2);
		}
	}
	else
	{
		cmd_path = find_cmd_absolute_path(cmd_name, envp);
		if (cmd_path == NULL)
		{
			ft_putstr_fd("Command not found: ", 2);
			ft_putstr_fd(cmd_name, 2);
			ft_putchar_fd('\n', 2);
		}
	}
	return (cmd_path);
}
