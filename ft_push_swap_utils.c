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
t_stack_node	*find_last(t_stack_node *stack) //encontrar puntero al ultimo bloque del stack
{
	if (!stack)
		return (NULL);
	while (stack->next) //bucle hasta encontrar el ultimo bloque del stack
		stack = stack->next;
	return (stack);
}

int	stack_len(t_stack_node *stack) //conseguir la longitud del stack
{
	int i;
	if (!stack)
		return (0);
	i = 0;
	while(stack)
	{
		i++; //subimos el contador 
		stack = stack->next;
	}
	return (i);
}

bool	stack_sorted(t_stack_node *stack) //comprobamos si el stack esta ordenado
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

t_stack_node	*find_min(t_stack_node *stack) //buscamos el nodo del stack que tenga el menor numero
{
	long			min; //aqui guardaremos el numero
	t_stack_node	*min_node; //aqui un nodo que apunte a dicho numero

	if (!stack)
		return (NULL);
	min = LONG_MAX; //inicializamos min al maximo valor posible
	while (stack) //recorremos el bucle
	{
		if (stack->nbr < min) //si el nbr del nodo actual es menor que el anterior, cambiamos min
		{
			min = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_stack_node	*find_max(t_stack_node *stack) //buscamos el nodo del stack que tenga el menor numero
{
	long			max; //aqui guardaremos el numero
	t_stack_node	*max_node; //aqui un nodo que apunte a dicho numero

	max = LONG_MIN; //inicializamos max al minimo valor posible
	while (stack) //recorremos el bucle
	{
		if (stack->nbr > max) //si el nbr del nodo actual es mayor que el anterior, cambiamos max
		{
			max = stack->nbr;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
