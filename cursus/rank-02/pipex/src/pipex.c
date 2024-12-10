/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:04:12 by mrios-es          #+#    #+#             */
/*   Updated: 2024/12/10 22:22:17 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_array(char **arr)
{
	int	i;

	ft_printf("[ \"%s\"", arr[0]);
	i = 1;
	while (arr[i])
	{
		ft_printf(", \"%s\"", arr[i]);
		i++;
	}
	ft_printf(" ]\n");
}

void	print_pipex(t_pipex *pipex)
{
	ft_printf("--------------------- pipex ---------------------\n");
	ft_printf(" infile: \"%s\"\n", pipex->infile);
	ft_printf("   cmd1: ");
	print_array(pipex->cmd1.cmd);
	ft_printf("   cmd2: ");
	print_array(pipex->cmd2.cmd);
	ft_printf("outfile: \"%s\"\n", pipex->outfile);
	ft_printf("------------------- end pipex -------------------\n");
}

int	check_path(t_cmd *cmd, char *dir)
{
	char	*aux;
	char	*cmd_path;

	if (cmd->cmd_full_path && ft_strlen(cmd->cmd_full_path))
		return (0);
	aux = ft_strjoin(dir, "/");
	if (!aux)
		return (1);
	cmd_path = ft_strjoin(aux, cmd->cmd[0]);
	free(aux);
	if (!cmd_path)
		return (1);
	if (access(cmd_path, X_OK) == 0)
		cmd->cmd_full_path = cmd_path;
	else
		free(cmd_path);
	return (0);
}

int	find_commands(t_pipex *pipex)
{
	char	**path_parts;
	int		i;

	path_parts = ft_split(pipex->PATH, ':');
	if (!path_parts)
		return (free_array(path_parts), 1);
	i = 0;
	while (path_parts[i])
	{
		if (check_path(&pipex->cmd1, path_parts[i])
			|| check_path(&pipex->cmd2, path_parts[i]))
			return (free_array(path_parts), 1);
		i++;
	}
	free_array(path_parts);
	ft_printf("cmd 1 full path: %s\n", pipex->cmd1.cmd_full_path);
	ft_printf("cmd 2 full path: %s\n", pipex->cmd2.cmd_full_path);
	return (!pipex->cmd1.cmd_full_path || !pipex->cmd2.cmd_full_path);
}

int	find_path(t_pipex *pipex, char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			pipex->PATH = env[i] + 5;
			break ;
		}
		i++;
	}
	ft_printf("PATH: %s\n", pipex->PATH);
	return (!pipex->PATH);
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
	pipex->PATH = NULL;
	pipex->cmd1.cmd_full_path = NULL;
	pipex->cmd2.cmd_full_path = NULL;

	print_pipex(pipex);

	return (0);
}

int	find_files(t_pipex *pipex)
{
	int	err;

	err = 0;
	pipex->infile.fd = open(pipex->infile.name, O_RDONLY);
	if (pipex->infile.fd < 0)
		err += ft_printf("%s: Permission denied\n", pipex->infile.name);
	if (access(pipex->outfile.name, F_OK) == 0
		&& access(pipex->outfile.name, W_OK) != 0)
		err += ft_printf("%s: Permission denied\n", pipex->outfile.name);
	return (err);
}

int	run_commands(t_pipex *pipex)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		return (ft_printf("Failed creating pipe!\n"));
	pid = fork();
	if (pid == -1)
		return (ft_printf("Failed forking!\n"));
	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		return (execve(pipex->cmd1.cmd_full_path, pipex->cmd1.cmd, NULL));
	}
	wait(NULL);
	pipex->outfile.fd = open(pipex->outfile.name, O_RDWR | O_CREAT, 0644);
	if (pipex->outfile.fd < 0)
		return (ft_printf("Failed creating output file!\n"));
	pid = fork();
	if (pid == -1)
		return (ft_printf("Failed forking!\n"));
	if (pid == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(pipex->outfile.fd, STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		return (execve(pipex->cmd2.cmd_full_path, pipex->cmd2.cmd, NULL));
	}
	close(fd[0]);
	close(fd[1]);
	wait(NULL);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	if (argc != 5)
		return (ft_printf("Bad arguments!\n$ ./pipex file1 cmd1 cmd2 file2\n"));
	if (init(&pipex, argv))
		return (ft_printf("Failed initializing pipex!\n"));
	if (find_files(&pipex))
		return (free_pipex(&pipex), ft_printf("File(s) not found!\n"));
	if (find_path(&pipex, env))
		return (free_pipex(&pipex), ft_printf("PATH not found!\n"));
	if (find_commands(&pipex))
		return (free_pipex(&pipex), ft_printf("Command(s) not found!\n"));
	if (run_commands(&pipex))
		return (free_pipex(&pipex), ft_printf("Failed running commands!\n"));
	free_pipex(&pipex);
	return (0);
}
