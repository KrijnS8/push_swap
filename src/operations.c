/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/05 17:00:39 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/12/07 16:51:06 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	ra(t_stack **stack_a)
{
	if (!rotate(stack_a))
		return (0);
	ft_printf("ra\n");
	return (1);
}

int	pa(t_stack **stack_a, t_stack **stack_b)
{
	int	value;
	int	index;

	index = (*stack_b)->index;
	if (!pop(stack_b, &value))
		return (0);
	if (!push(stack_a, value, index))
		return (0);
	ft_printf("pa\n");
	return (1);
}

int	pb(t_stack **stack_a, t_stack **stack_b)
{
	int	value;
	int	index;

	index = (*stack_a)->index;
	if (!pop(stack_a, &value))
		return (0);
	if (!push(stack_b, value, index))
		return (0);
	ft_printf("pb\n");
	return (1);
}
