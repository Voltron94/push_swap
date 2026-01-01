#include "libft.h"

int	is_sort(t_list *stack, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (stack->index > stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	two_case(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->index > (*stack_a)->next->index)
		swap(stack_a, stack_b, 'a');
}

void	three_case_next(t_list **stack_a, t_list **stack_b)
{
	int	first;
	int	second;
	int	last;

	first = (*stack_a)->index;
	second = (*stack_a)->next->index;
	last = (*stack_a)->next->next->index;
	if (first > second && second < last && first > last)
		rotate(stack_a, stack_b, 'a');
	else if (first > second && second < last)
		swap(stack_a, stack_b, 'a');
	else if (first < second && second > last)
	{
		rotate(stack_a, stack_b, 'a');
		rotate(stack_a, stack_b, 'a');
		swap(stack_a, stack_b, 'a');
	}
}

void	three_case(t_list **stack_a, t_list **stack_b)
{
	int	first;
	int	second;
	int	last;

	first = (*stack_a)->index;
	second = (*stack_a)->next->index;
	last = (*stack_a)->next->next->index;
	if (first > second && second > last)
	{
		rotate(stack_a, stack_b, 'a');
		swap(stack_a, stack_b, 'a');
	}
	else if (first < second && second > last && first > last)
	{
		rotate(stack_a, stack_b, 'a');
		rotate(stack_a, stack_b, 'a');
	}
	three_case_next(stack_a, stack_b);
}

// push(&stack_a, &stack_b, 'a');
// swap(&stack_a, &stack_b, 'a');
// rotate(&stack_a, &stack_b, 'a');
// reverse_rotate(&stack_a, &stack_b, 'a');