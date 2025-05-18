/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:12:16 by marvin            #+#    #+#             */
/*   Updated: 2025/05/03 16:12:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_target_to_top(
	t_stack_node **stack,
	t_stack_node *top_node,
	char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'A')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

void	ft_sort_three(t_stack_node **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->nbr;
	b = (*stack)->next->nbr;
	c = (*stack)->next->next->nbr;
	if (a > b && b < c && a < c)
		sa(stack, false);
	else if (a > b && b > c)
	{
		sa(stack, false);
		rra(stack, false);
	}
	else if (a > b && b < c && a > c)
		ra(stack, false);
	else if (a < b && b > c && a < c)
	{
		sa(stack, false);
		ra(stack, false);
	}
	else if (a < b && b > c && a > c)
		rra(stack, false);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	init_stack_a(&a, argv + 1);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			ft_sort_three(&a);
		else
			ft_turk(&a, &b);
	}
	free_stack(&a);
	return (0);
}
