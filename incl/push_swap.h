/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/05 14:46:32 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/12/07 16:56:20 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_stack	t_stack;

typedef struct s_stack
{
	int		data;
	int		index;
	t_stack	*next;
}	t_stack;

// Sort functions
int		radix_sort(t_stack **stack_a, t_stack **stack_b);
int		is_sorted(t_stack *stack);

// Stack functions
t_stack	*create_node(int content);
int		push(t_stack **top, int value, int index);
int		pop(t_stack **top, int *to_fill);
int		rotate(t_stack **top);
void	destroy_stack(t_stack **top);
void	print_stack(t_stack *top);
t_stack	*get_bottom(t_stack *top);
size_t	stack_size(t_stack *stack);
void	stack_add_back(t_stack **stack, t_stack *new);

// Operations
int		pa(t_stack **stack_a, t_stack **stack_b);
int		pb(t_stack **stack_a, t_stack **stack_b);
int		ra(t_stack **stack_a);

#endif
