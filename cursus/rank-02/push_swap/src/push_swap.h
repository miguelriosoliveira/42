/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:41:29 by mrios-es          #+#    #+#             */
/*   Updated: 2024/12/27 10:15:09 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define A 'a'
# define B 'b'

typedef struct s_stack
{
	int	size;
	int	*stack;
}	t_stack;

// operations.c
void	s(t_stack *stack, char stack_id);
void	ss(t_stack *stack_a, t_stack *stack_b);

// utils.c
int		is_sorted(t_stack *stack);
void	print_stacks(t_stack *stack_a, t_stack *stack_b);
void	free_str_array(char **arr);
void	strarr_to_intarr(char **strarr, int *intarr);

// validation.c
int		validate_args(int argc, char **argv);

#endif
