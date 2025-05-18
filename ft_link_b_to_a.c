/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_b_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperales <cperales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 22:29:12 by cperales          #+#    #+#             */
/*   Updated: 2025/05/18 09:58:17 by cperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// Define a function that sets for the current `a` node,
// its target node from stack `a`
void	ft_set_target_b(t_stack_node *a, t_stack_node *b) //Define a function that sets for the current `a` node, its target node from stack `a`
{
	t_stack_node	*current_a; //To store the pointer to the current `a` node
	t_stack_node	*target_node; //To store the pointer of the target node for `b` node
	long			best_match_index; //To store the "closest bigger" number so far

	while (b)
	{
		best_match_index = LONG_MAX; //Set the current best match to the max long
		current_a = a; //Assign the pointer to point to the current `a` node
		while (current_a) //While the pointer is not set to NULL
		{
			if (current_a->nbr > b->nbr 
				&& current_a->nbr < best_match_index) //Check if the `a` node's value is bigger than `b` node, && smaller than the "closest bigger" so far
			{
				best_match_index = current_a->nbr; //Set the best match as the value in the current `a` node
				target_node = current_a; //Set `b` node's target node pointer to point to the current `a` node
			}
			current_a = current_a->next; //Move to the next `a` node for processing
		}
		if (best_match_index == LONG_MAX) //If the best match value has not changed
			b->target_node = find_min(a); //Set `b` node's target node pointer to point to the smallest number in stack `a`
		else
			b->target_node = target_node; //If the best match value has been updated, then we have a target node for the current `b` node
		b = b->next; //Move to the next `b` node for processing
	}
}

void	ft_link_b_to_a(t_stack_node *a, t_stack_node *b)
{
	ft_current_index(a);
	ft_current_index(b);
	ft_set_target_b(a, b);
}
