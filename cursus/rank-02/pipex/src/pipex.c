/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:04:12 by mrios-es          #+#    #+#             */
/*   Updated: 2025/01/05 18:38:19 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	find_files(t_pipex *pipex)
{
	int	err;

	err = 0;
	if (access(pipex->infile.name, F_OK) != 0)
		err += ft_printf("%s: No such file or directory\n", pipex->infile.name);
	else
	{
		pipex->infile.fd = open(pipex->infile.name, O_RDONLY);
		if (pipex->infile.fd < 0)
			err += ft_printf("%s: Permission denied\n", pipex->infile.name);
	}
	if (access(pipex->outfile.name, F_OK) == 0
		&& access(pipex->outfile.name, W_OK) != 0)
		err += ft_printf("%s: Permission denied\n", pipex->outfile.name);
	return (err);
}

static int	find_path(t_pipex *pipex, char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			pipex->the_path = env[i] + 5;
			break ;
		}
		i++;
	}
	return (!pipex->the_path);
}

static int	find_commands(t_pipex *pipex)
{
	char	**path_parts;
	int		i;

	path_parts = ft_split(pipex->the_path, ':');
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
	return (!pipex->cmd1.cmd_full_path || !pipex->cmd2.cmd_full_path);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	if (argc != 5)
		return (ft_printf("Bad arguments!\n./pipex file1 cmd1 cmd2 file2\n"));
	if (init(&pipex, argv))
		return (ft_printf("Failed initializing pipex!\n"));
	if (find_files(&pipex))
		return (free_pipex(&pipex), ft_printf("Failed handling files!\n"));
	if (find_path(&pipex, env))
		return (free_pipex(&pipex), ft_printf("PATH not found!\n"));
	if (find_commands(&pipex))
		return (free_pipex(&pipex), ft_printf("Command(s) not found!\n"));
	if (run_commands(&pipex, env))
		return (free_pipex(&pipex), ft_printf("Failed running commands!\n"));
	free_pipex(&pipex);
	return (0);
}
