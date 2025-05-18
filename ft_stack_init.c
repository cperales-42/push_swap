/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperales <cperales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 23:46:34 by cperales          #+#    #+#             */
/*   Updated: 2025/05/18 09:55:21 by cperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// como el atoi pero para longs
static long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
		*s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

// añadimos un nodo al stack en el ultimo valor de la lista
static void	ft_append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node; // puntero al nuevo nodo con valor 'n'
	t_stack_node	*last_node; // último nodo del stack

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node)); // asignamos memoria
	if (!node)
		return ;
	node->next = NULL; // último nodo -> siguiente será NULL
	node->nbr = n; // le damos el valor n
	node->cheapest = 0; // inicializamos

	if (!(*stack)) // si el stack está vacío o apunta a NULL
	{
		*stack = node; // lo asignamos como primer nodo
		node->prev = NULL; // también es el primero
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node; // el anterior apunta al nuevo
		node->prev = last_node; // el nuevo apunta al anterior
	}
}

void	init_stack_a(t_stack_node **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (ft_syntax_error(argv[i]))
			free_errors(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN) // comprobamos overflow
			free_errors(a);
		if (ft_duplicate_error(*a, (int)n))
			free_errors(a);
		ft_append_node(a, (int)n);
		i++;
	}
}

t_stack_node	*ft_get_cheapest(t_stack_node *a)
{
	while (a)
	{
		if (a->cheapest) // si es el más barato lo devolvemos
			return (a);
		a = a->next;
	}
	return (NULL);
}

void	ft_move_node_to_top(t_stack_node **stack, char stackName)
{
	t_stack_node	*cheapest;

	if (!*stack)
		return ;
	cheapest = ft_get_cheapest(*stack); // encuentra el más barato
	while (*stack != cheapest) // rotamos hasta que esté en la cima
	{
		if (cheapest->above_median) // si está por encima de la mediana
		{
			if (stackName == 'A')
				ra(stack, false);
			else
				rb(stack, false);
		}
		else // si está por debajo, reverse rotate
		{
			if (stackName == 'A')
				rra(stack, false);
			else
				rrb(stack, false);
		}
	}
}
