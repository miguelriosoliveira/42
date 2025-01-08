/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:04:12 by mrios-es          #+#    #+#             */
/*   Updated: 2025/01/08 19:27:36 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	find_input_file(t_pipex *pipex)
{
	if (access(pipex->infile.name, F_OK) != 0)
		return (print_error(pipex->infile.name), EXIT_FAILURE);
	pipex->infile.fd = open(pipex->infile.name, O_RDONLY);
	if (pipex->infile.fd < 0)
		return (print_error(pipex->infile.name), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	find_output_file(t_pipex *pipex)
{
	if (access(pipex->outfile.name, F_OK) != 0)
	{
		if (ft_strlen(pipex->outfile.name) == 0)
			return (print_error(pipex->outfile.name), EXIT_FAILURE);
	}
	else if (access(pipex->outfile.name, W_OK) != 0)
		return (print_error(pipex->outfile.name), EXIT_FAILURE);
	return (EXIT_SUCCESS);
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
	int		result;

	path_parts = ft_split(pipex->the_path, ':');
	if (!path_parts)
		return (free_array(path_parts), 1);
	i = 0;
	while (path_parts[i])
	{
		check_path(&pipex->cmd1, path_parts[i]);
		check_path(&pipex->cmd2, path_parts[i]);
		i++;
	}
	free_array(path_parts);
	result = !pipex->cmd1.cmd_full_path || !pipex->cmd2.cmd_full_path;
	if (!pipex->cmd1.cmd_full_path)
		print_command_not_found(&pipex->cmd1);
	if (!pipex->cmd2.cmd_full_path)
		print_command_not_found(&pipex->cmd2);
	if (result)
		return (result);
	return (result);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	if (argc != 5)
		return (ft_putstr_fd("Bad arguments!\n./pipex file1 cmd1 cmd2 file2\n",
				STDERR_FILENO));
	if (init(&pipex, argv))
		return (ft_putstr_fd("Failed initializing pipex!\n", STDERR_FILENO));
	if (find_input_file(&pipex) + find_output_file(&pipex))
		return (free_pipex(&pipex), EXIT_FAILURE);
	if (find_path(&pipex, env))
		return (free_pipex(&pipex), ft_putstr_fd("PATH not found!\n",
				STDERR_FILENO));
	if (find_commands(&pipex))
		return (free_pipex(&pipex), EXIT_FAILURE);
	if (run_commands(&pipex, env))
		return (free_pipex(&pipex), ft_putstr_fd("Failed running commands!\n",
				STDERR_FILENO));
	free_pipex(&pipex);
	return (0);
}
