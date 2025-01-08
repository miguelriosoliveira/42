/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:25:11 by mrios-es          #+#    #+#             */
/*   Updated: 2025/01/08 17:48:50 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_command_not_found(t_cmd *cmd)
{
	ft_putstr_fd("bash: ", STDERR_FILENO);
	if (cmd->cmd[0])
		ft_putstr_fd(cmd->cmd[0], STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
}

void	print_error(char *prefix)
{
	ft_putstr_fd("bash: ", STDERR_FILENO);
	if (prefix && ft_strlen(prefix) == 0)
		ft_putstr_fd(": ", STDERR_FILENO);
	perror(prefix);
}
