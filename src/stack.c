/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/05 14:46:07 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/12/07 16:51:16 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

t_stack	*create_node(int content)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->data = content;
	node->index = -1;
	node->next = NULL;
	return (node);
}

int	push(t_stack **top, int value, int index)
{
	t_stack	*node;

	node = create_node(value);
	if (!node)
		return (0);
	node->next = *top;
	node->index = index;
	*top = node;
	return (1);
}

int	pop(t_stack **top, int *to_fill)
{
	t_stack	*tmp;

	if (*top == NULL)
		return (0);
	*to_fill = (*top)->data;
	tmp = *top;
	*top = (*top)->next;
	free(tmp);
	return (1);
}

int	rotate(t_stack **top)
{
	t_stack	*head;
	t_stack	*tail;

	if (stack_size(*top) < 2)
		return (0);
	head = *top;
	tail = get_bottom(*top);
	*top = head->next;
	head->next = NULL;
	tail->next = head;
	return (1);
}

void	destroy_stack(t_stack **top)
{
	t_stack	*tmp;

	while (*top != NULL)
	{
		tmp = *top;
		*top = (*top)->next;
		free(tmp);
	}
}
