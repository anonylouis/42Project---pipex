/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:54:22 by lcalvie           #+#    #+#             */
/*   Updated: 2022/01/16 17:14:16 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

typedef struct s_command
{
	char	*path;
	char	**args;
	int		pipefds[2];
	int		fd_in;
	int		fd_out;
}		t_command;

#endif