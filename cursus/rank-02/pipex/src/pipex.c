/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:04:12 by mrios-es          #+#    #+#             */
/*   Updated: 2024/11/03 17:55:44 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_path(t_pipex *pipex, char *dir)
{
	int		i;
	char	*aux;
	char	*cmd_path;

	i = 0;
	while (i < MAX_CMDS)
	{
		if (pipex->cmds_full_path[i] && ft_strlen(pipex->cmds_full_path[i]))
		{
			i++;
			continue ;
		}
		aux = ft_strjoin(dir, "/");
		if (!aux)
			return (1);
		cmd_path = ft_strjoin(aux, pipex->cmds[i]);
		free(aux);
		if (!cmd_path)
			return (1);
		if (access(cmd_path, X_OK) == 0)
			pipex->cmds_full_path[i] = cmd_path;
		else
			free(cmd_path);
		i++;
	}
	return (0);
}

int	find_commands(t_pipex *pipex)
{
	char	**path_parts;
	int		i;

	path_parts = ft_split(ft_strchr(pipex->path, '=') + 1, ':');
	if (!path_parts)
		return (free_array(path_parts), 1);
	i = 0;
	while (path_parts[i])
	{
		if (check_path(pipex, path_parts[i]))
			return (free_array(path_parts), 1);
		i++;
	}
	ft_printf("pipex->cmds_full_path[0]: %s\n", pipex->cmds_full_path[0]);
	ft_printf("pipex->cmds_full_path[1]: %s\n", pipex->cmds_full_path[1]);
	return (free_array(path_parts), 0);
}

int	find_path(t_pipex *pipex, char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			pipex->path = env[i];
			break ;
		}
		i++;
	}
	if (!pipex->path)
		return (1);
	ft_printf("%s\n", pipex->path);
	return (0);
}

int	init(t_pipex *pipex, char **argv)
{
	int		space_pos;
	char	*cmd_args;

	pipex->files[0] = argv[1];
	pipex->cmds_with_args[0] = argv[2];
	pipex->cmds_with_args[1] = argv[3];
	pipex->files[1] = argv[4];
	pipex->path = NULL;
	space_pos = 0;
	cmd_args = ft_strchr(pipex->cmds_with_args[0], ' ');
	if (cmd_args)
		space_pos = cmd_args - pipex->cmds_with_args[0];
	pipex->cmds[0] = ft_substr(pipex->cmds_with_args[0], 0, space_pos);
	if (!pipex->cmds[0])
		return (1);
	cmd_args = ft_strchr(pipex->cmds_with_args[1], ' ');
	if (cmd_args)
		space_pos = cmd_args - pipex->cmds_with_args[1];
	pipex->cmds[1] = ft_substr(pipex->cmds_with_args[1], 0, space_pos);
	if (!pipex->cmds[1])
		return (free(pipex->cmds[0]), 1);
	ft_printf("%s %s %s %s\n", pipex->files[0], pipex->cmds[0], pipex->cmds[1],
		pipex->files[1]);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	if (argc != 5)
		return (ft_printf("Bad arguments!\n$ ./pipex file1 cmd1 cmd2 file2\n"));
	if (init(&pipex, argv))
		return (ft_printf("Failed initializing pipex\n"));
	if (find_path(&pipex, env))
		return (ft_printf("PATH not found!\n"));
	if (find_commands(&pipex))
		return (ft_printf("Failed finding commands in PATH\n"));
	free_pipex(&pipex);
	return (0);
}
