/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_a_to_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperales <cperales@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 21:42:39 by cperales          #+#    #+#             */
/*   Updated: 2025/05/26 01:25:00 by cperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_current_index(t_stack_node *stack)
// inicializa indices y su valor respecto a la mediana
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	ft_set_target_a(t_stack_node *a, t_stack_node *b) // linkea a a b
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			best_match;

	while (a)
	{
		best_match = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->nbr < a->nbr && current_b->nbr > best_match)
			{
				target_node = current_b;
				best_match = current_b->nbr;
			}
			current_b = current_b->next;
		}
		if (best_match == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void	ft_cost_analysis_a(t_stack_node *a, int len_a, int len_b)
{
	int	cost_a;
	int	cost_b;

	while (a)
	{
		if (a->above_median)
			cost_a = a->index;
		else
			cost_a = len_a - a->index;
		if (a->target_node->above_median)
			cost_b = a->target_node->index;
		else
			cost_b = len_b - a->target_node->index;
		if ((a->above_median && a->target_node->above_median)
			|| (!a->above_median && !a->target_node->above_median))
		{
			if (cost_a > cost_b)
				a->push_cost = cost_a;
			else
				a->push_cost = cost_b;
		}
		else
			a->push_cost = cost_a + cost_b;
		a = a->next;
	}
}

void	ft_set_cheapest(t_stack_node *stack) // encuentra el push mas barato
{
	t_stack_node	*cheapest_node;
	long			cheapest;

	if (!stack)
		return ;
	cheapest = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest)
		{
			cheapest = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	ft_link_a_to_b(t_stack_node *a, t_stack_node *b)
// se asegura de cumplir todo para que el push sea el mas barato posible
{
	ft_current_index(a);
	ft_current_index(b);
	ft_set_target_a(a, b);
	ft_cost_analysis_a(a, stack_len(a), stack_len(b));
	ft_set_cheapest(a);
}
