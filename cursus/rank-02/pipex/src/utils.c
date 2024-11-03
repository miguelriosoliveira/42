/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:31:51 by migrio            #+#    #+#             */
/*   Updated: 2024/11/03 17:18:10 by mrios-es         ###   ########.fr       */
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
	int	i;

	i = 0;
	while (i < MAX_CMDS)
	{
		free(pipex->cmds[i]);
		free(pipex->cmds_full_path[i]);
		i++;
	}
}
