/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperales <cperales@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 03:05:46 by cperales          #+#    #+#             */
/*   Updated: 2025/05/25 03:05:46 by cperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_target_to_top(t_stack_node **stack, t_stack_node *top_node,
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

static void	push(t_stack_node **src, t_stack_node **dst)
{
	t_stack_node	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dst)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool print) // push a
{
	push(b, a);
	if (!print)
		ft_printf("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a, bool print) // push b
{
	push(a, b);
	if (!print)
		ft_printf("pb\n");
}
