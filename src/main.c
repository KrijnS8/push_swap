/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/05 13:10:41 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/12/07 16:58:27 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "../incl/push_swap.h"

bool	validate_args(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		if (!ft_is_integer(argv[i]))
			return (false);
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

t_stack	*get_next_min(t_stack *stack)
{
	t_stack	*min;

	min = NULL;
	while (stack)
	{
		if (stack->index == -1 && (min == NULL || stack->data < min->data))
			min = stack;
		stack = stack->next;
	}
	return (min);
}

void	index_stack(t_stack *stack)
{
	t_stack	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = get_next_min(stack);
	}
}

t_stack	*init_stack_a(int argc, char *argv[])
{
	t_stack	*stack;
	t_stack	*new;
	int		i;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		new = create_node(ft_atoi(argv[i]));
		if (!new)
			return (destroy_stack(&stack), NULL);
		stack_add_back(&stack, new);
		i++;
	}
	index_stack(stack);
	return (stack);
}

int	main(int argc, char *argv[])
{
	int		*arr;
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 1 || !validate_args(argc, argv))
		return (ft_printf("Error\n"), 1);
	stack_b = NULL;
	stack_a = init_stack_a(argc, argv);
	if (stack_a == NULL)
		return (ft_printf("Error\n"), 1);
	if (is_sorted(stack_a))
		return (destroy_stack(&stack_a), 0);
	radix_sort(&stack_a, &stack_b);
	destroy_stack(&stack_a);
	return (0);
}
