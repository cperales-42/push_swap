/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperales <cperales@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 01:33:21 by cperales          #+#    #+#             */
/*   Updated: 2025/05/26 01:33:21 by cperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// encontrar puntero al ultimo bloque del stack
t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

// conseguir la longitud del stack
int	stack_len(t_stack_node *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

// comprobamos si el stack está ordenado
bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->nbr < stack->next->nbr)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}

// buscamos el nodo del stack que tenga el menor numero
t_stack_node	*find_min(t_stack_node *stack)
{
	long			min;
	t_stack_node	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < min)
		{
			min = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

// buscamos el nodo del stack que tenga el mayor numero
t_stack_node	*find_max(t_stack_node *stack)
{
	long			max;
	t_stack_node	*max_node;

	max = LONG_MIN;
	while (stack)
	{
		if (stack->nbr > max)
		{
			max = stack->nbr;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
