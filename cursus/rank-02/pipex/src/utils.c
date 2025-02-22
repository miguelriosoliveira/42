/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:31:51 by mrios-es          #+#    #+#             */
/*   Updated: 2025/01/08 20:12:47 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_pipex(t_pipex *pipex)
{
	free_array(pipex->cmd1.cmd);
	free(pipex->cmd1.cmd_full_path);
	free_array(pipex->cmd2.cmd);
	free(pipex->cmd2.cmd_full_path);
	if (pipex->infile.fd >= 0)
		close(pipex->infile.fd);
	if (pipex->outfile.fd >= 0)
		close(pipex->outfile.fd);
}

int	is_local_bin(char *path)
{
	return (ft_strncmp(path, "/", 1) == 0
		|| ft_strncmp(path, "./", 2) == 0
		|| ft_strncmp(path, "../", 3) == 0);
}

int	check_path(t_cmd *cmd, char *dir)
{
	char	*aux;
	char	*cmd_path;

	if (!cmd->cmd[0])
		return (EXIT_FAILURE);
	if (is_local_bin(cmd->cmd[0]) && access(cmd->cmd[0], X_OK) == 0)
	{
		cmd->cmd_full_path = ft_strdup(cmd->cmd[0]);
		return (EXIT_SUCCESS);
	}
	if (cmd->cmd_full_path && ft_strlen(cmd->cmd_full_path))
		return (EXIT_SUCCESS);
	aux = ft_strjoin(dir, "/");
	if (!aux)
		return (EXIT_FAILURE);
	cmd_path = ft_strjoin(aux, cmd->cmd[0]);
	free(aux);
	if (!cmd_path)
		return (EXIT_FAILURE);
	if (access(cmd_path, X_OK) == 0)
		cmd->cmd_full_path = cmd_path;
	else
		free(cmd_path);
	return (EXIT_SUCCESS);
}

int	init(t_pipex *pipex, char **argv)
{
	pipex->infile.name = argv[1];
	pipex->cmd1.cmd = ft_split(argv[2], ' ');
	if (!pipex->cmd1.cmd)
		return (1);
	pipex->cmd2.cmd = ft_split(argv[3], ' ');
	if (!pipex->cmd2.cmd)
		return (free_array(pipex->cmd1.cmd), 1);
	pipex->outfile.name = argv[4];
	pipex->the_path = NULL;
	pipex->cmd1.cmd_full_path = NULL;
	pipex->cmd2.cmd_full_path = NULL;
	return (0);
}
