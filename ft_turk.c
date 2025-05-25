/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperales <cperales@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:41:14 by cperales          #+#    #+#             */
/*   Updated: 2025/05/25 04:04:42 by cperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	cheapest = ft_get_cheapest(*a);
	while (*a != cheapest && *b != cheapest->target_node
		&& cheapest->above_median && cheapest->target_node->above_median)
		rr(a, b, false);
	while (*a != cheapest && *b != cheapest->target_node
		&& !cheapest->above_median && !cheapest->target_node->above_median)
		rrr(a, b, false);
	ft_move_node_to_top(a, 'A');
	if (cheapest->target_node->prev)
		ft_target_to_top(b, cheapest->target_node, 'B');
	pb(b, a, false);
}

void	ft_move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	ft_target_to_top(a, (*b)->target_node, 'A');
	pa(a, b, false);
}

void	ft_turk(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && stack_len(*b) < 2 && !stack_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && stack_len(*b) < 2 && !stack_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		ft_link_a_to_b(*a, *b);
		ft_move_a_to_b(a, b);
	}
	ft_sort_three(a);
	while (*b)
	{
		ft_link_b_to_a(*a, *b);
		ft_move_b_to_a(a, b);
	}
	ft_current_index(*a);
	ft_target_to_top(a, find_min(*a), 'A');
}
