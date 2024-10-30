/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:04:12 by mrios-es          #+#    #+#             */
/*   Updated: 2024/10/30 20:45:10 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	(void)env;
	int		i;
	char	*files[2];
	char	*cmds[2];

	if (argc != 5)
		return (ft_printf("Bad arguments!\n$ ./pipex file1 cmd1 cmd2 file2\n"));

	files[0] = argv[1];
	cmds[0] = argv[2];
	cmds[1] = argv[3];
	files[1] = argv[4];
	ft_printf("files[0]: \"%s\"\n", files[0]);
	ft_printf(" cmds[0]: \"%s\"\n", cmds[0]);
	ft_printf(" cmds[1]: \"%s\"\n", cmds[1]);
	ft_printf("files[1]: \"%s\"\n", files[1]);

	i = 0;
	while (env[i])
	{
		ft_printf("[%2d] %s\n", i+1, env[i]);
		i++;
	}

	return (0);
}
