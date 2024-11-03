/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:05:36 by mrios-es          #+#    #+#             */
/*   Updated: 2024/11/03 17:55:31 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"

# define MAX_CMDS 2

typedef struct s_pipex
{
	char	*files[2];
	char	*cmds[2];
	char	*cmds_with_args[2];
	char	*path;
	char	*cmds_full_path[2];
}	t_pipex;

// utils.c
void	free_array(char **arr);
void	free_pipex(t_pipex *pipex);

#endif
