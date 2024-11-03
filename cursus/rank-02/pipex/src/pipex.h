/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:05:36 by mrios-es          #+#    #+#             */
/*   Updated: 2024/11/03 18:26:02 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"

typedef struct s_cmd
{
	char	**cmd;
	char	*cmd_full_path;
}	t_cmd;

typedef struct s_pipex
{
	char	*PATH;
	char	*infile;
	char	*outfile;
	t_cmd	cmd1;
	t_cmd	cmd2;
}	t_pipex;

// utils.c
void	free_array(char **arr);
void	free_pipex(t_pipex *pipex);

#endif
