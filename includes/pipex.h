/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonylouis <anonylouis@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:29:12 by lcalvie           #+#    #+#             */
/*   Updated: 2022/01/17 00:24:16 by anonylouis       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "command.h"
# define BUFFER_SIZE 4096

typedef struct s_pipex
{
	t_command	*cmd;
	int			fd_infile;
	int			fd_outfile;
	int			here_doc;
	int			outfile_flags;
	char		*limiter;
}		t_pipex;

int		exec_all_cmds(int argc, char **argv, char **envp, t_pipex *pipex);

// PIPEX
t_pipex	*new_pipex(int argc, char **argv);
int		fill_pipex(t_pipex *pipex, int argc, char **argv, char **envp);
void	free_pipex(t_pipex *pipex);

// COMMAND
int		new_command(char *cmd_name, t_command **cmd, char **envp);
void	free_command(t_command *cmd);

// ARGUMENTS
int		find_cmd_and_args(char *cmd_name,
			char **envp, char **cmd, char ***args);
char	*find_cmd_path(char *cmd_name, char **envp);

// STDIN
void	read_stdin(t_pipex *pipex);

// PRINT
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

// UTILS
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
void	free_tab(char **tab);
char	*ft_strdup(char *src);
int		check_null( char **tab, int len);
int		is_in_str(char *str, char c);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*get_next_line(int fd);
char	*ft_concat(char *s1, char *s2);
char	*ft_strndup(char *src, int size);

#endif