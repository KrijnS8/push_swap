/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/05 17:07:58 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/12/07 16:51:12 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	print_stack(t_stack *top)
{
	while (top != NULL)
	{
		ft_printf("%d\t\t%d\n", top->data, top->index);
		top = top->next;
	}
}

t_stack	*get_bottom(t_stack *top)
{
	while (top->next != NULL)
		top = top->next;
	return (top);
}

size_t	stack_size(t_stack *stack)
{
	size_t	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*n;

	if (*stack)
	{
		n = get_bottom(*stack);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}
