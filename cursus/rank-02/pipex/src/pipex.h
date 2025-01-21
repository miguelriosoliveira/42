/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:05:36 by mrios-es          #+#    #+#             */
/*   Updated: 2025/01/08 20:13:02 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <sys/wait.h>
# include "../libft/libft.h"

# define TMP_FILE "tmp.txt"

typedef struct s_file
{
	char	*name;
	int		fd;
}	t_file;

typedef struct s_cmd
{
	char	**cmd;
	char	*cmd_full_path;
}	t_cmd;

typedef struct s_pipex
{
	char	*the_path;
	t_file	infile;
	t_file	outfile;
	t_cmd	cmd1;
	t_cmd	cmd2;
}	t_pipex;

// commands.c
int		run_commands(t_pipex *pipex, char **env);

// errors.c
void	print_command_not_found(t_cmd *cmd);
void	print_error(char *prefix);

// utils.c
void	free_array(char **arr);
void	free_pipex(t_pipex *pipex);
int		is_local_bin(char *path);
int		check_path(t_cmd *cmd, char *dir);
int		init(t_pipex *pipex, char **argv);

#endif
