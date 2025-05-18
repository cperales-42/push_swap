/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:12:19 by marvin            #+#    #+#             */
/*   Updated: 2025/05/03 16:12:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// encontrar puntero al ultimo bloque del stack
t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next) // bucle hasta encontrar el ultimo bloque
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
		i++; // subimos el contador
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
	long			min; // aqui guardaremos el numero
	t_stack_node	*min_node; // nodo que apunta al menor numero

	if (!stack)
		return (NULL);
	min = LONG_MAX; // inicializamos al maximo valor posible
	while (stack) // recorremos el bucle
	{
		if (stack->nbr < min) // si el nodo actual es menor
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
	long			max; // aqui guardaremos el numero
	t_stack_node	*max_node; // nodo que apunta al mayor numero

	max = LONG_MIN; // inicializamos al minimo valor posible
	while (stack) // recorremos el bucle
	{
		if (stack->nbr > max) // si el nodo actual es mayor
		{
			max = stack->nbr;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
