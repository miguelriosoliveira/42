/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:59:13 by mrios-es          #+#    #+#             */
/*   Updated: 2025/01/05 19:54:27 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	run_first_command(int infilefd, int pipe[2], t_cmd *cmd, char **env)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		return (ft_printf("Failed forking!\n"));
	if (pid == 0)
	{
		dup2(infilefd, STDIN_FILENO);
		dup2(pipe[1], STDOUT_FILENO);
		close(pipe[0]);
		close(pipe[1]);
		return (execve(cmd->cmd_full_path, cmd->cmd, env));
	}
	return (0);
}

static int	run_last_command(char *outfile, int pipe[2], t_cmd *cmd, char **env)
{
	int	pid;
	int	output_fd;

	output_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_fd < 0)
		return (ft_printf("Failed creating output file!\n"));
	pid = fork();
	if (pid == -1)
		return (ft_printf("Failed forking!\n"));
	if (pid == 0)
	{
		dup2(pipe[0], STDIN_FILENO);
		dup2(output_fd, STDOUT_FILENO);
		close(pipe[0]);
		close(pipe[1]);
		return (execve(cmd->cmd_full_path, cmd->cmd, env));
	}
	return (0);
}

int	run_commands(t_pipex *pipex, char **env)
{
	int	fd[2];

	if (pipe(fd) == -1)
		return (ft_printf("Failed creating pipe!\n"));
	if (run_first_command(pipex->infile.fd, fd, &pipex->cmd1, env))
		return (ft_printf("Failed running command!\n"));
	wait(NULL);
	if (run_last_command(pipex->outfile.name, fd, &pipex->cmd2, env))
		return (ft_printf("Failed running command!\n"));
	close(fd[0]);
	close(fd[1]);
	wait(NULL);
	return (0);
}
