/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperales <cperales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:41:14 by cperales          #+#    #+#             */
/*   Updated: 2025/05/18 09:55:49 by cperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest; // variable para reducir complejidad

	cheapest = ft_get_cheapest(*a);
	while (*a != cheapest && *b != cheapest->target_node
		&& cheapest->above_median
		&& cheapest->target_node->above_median)
		rr(a, b, false); // rotamos ambos mientras no estén arriba y están en la misma mitad
	while (*a != cheapest && *b != cheapest->target_node
		&& !cheapest->above_median
		&& !cheapest->target_node->above_median)
		rrr(a, b, false); // hacer reverse rotate en ambos
	ft_move_node_to_top(a, 'A'); // encontramos el más barato de A y lo subimos al top
	if (cheapest->target_node->prev) // si el nodo objetivo del cheapest tiene previo
		ft_target_to_top(b, cheapest->target_node, 'B'); // lo movemos hasta la cima
	pb(b, a, false); // lo pusheamos a B
}

void	ft_move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	ft_target_to_top(a, (*b)->target_node, 'A');
	pa(a, b, false); // lo pusheamos a A
}

void	ft_turk(t_stack_node **a, t_stack_node **b)
{
	int	len_a; // para reducir la complejidad de la función

	len_a = stack_len(*a);
	if (len_a-- > 3 && stack_len(*b) < 2 && !stack_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && stack_len(*b) < 2 && !stack_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !stack_sorted(*a)) // hasta que en A solo hayan 3
	{
		ft_link_a_to_b(*a, *b); // linkeamos A a B
		ft_move_a_to_b(a, b); // movemos el más barato de A hasta B
	}
	ft_sort_three(a); // ordenamos los 3 existentes
	while (*b) // mientras haya algo en el stack de B
	{
		ft_link_b_to_a(*a, *b);
		ft_move_b_to_a(a, b);
	}
	ft_current_index(*a);
	ft_target_to_top(a, find_min(*a), 'A');
}
