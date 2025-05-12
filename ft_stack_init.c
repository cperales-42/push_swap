/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperales <cperales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 23:46:34 by cperales          #+#    #+#             */
/*   Updated: 2025/05/11 22:37:27 by cperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static long	ft_atol(const char *s) //como el atoi pero para longs
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
			sign = (-1);
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

static void ft_append_node(t_stack_node **stack, int n) //añadimos un nodo al stack en el ultimo valor de la lista
{
    t_stack_node    *node; //aqui guardaremos el puntero al nuevo nodo con el valor 'n'
    t_stack_node    *last_node; //aqui guadaremos el ultimo nodo del stack

    if (!stack)
        return ;
    node = malloc(sizeof(t_stack_node)); //asignamos memoria
    if (!node)
        return ;
    node->next = NULL; //como va a ser el ultimo, su siguiente sera null
    node->nbr = n; //le damos el valor n
    node->cheapest = 0; //inicializamos el valor

    if (!(*stack)) //comprobamos si el stack esta vacio o apunta a null
    {
        *stack = node; //si esta vacio le asignamos el nuevo nodo creado
        node->prev = NULL; //como el stack estaria vacio asignamos previo a null pq sería el ultimo pero tambien el primero
    }
    else
    {
        last_node = find_last(*stack);
        last_node->next = node; //como estamos metiendo un nuevo nodo su siguiente sera el nuevo
        node->prev = last_node; //el anterior del nuevo sera el antiguo anterior
    }
}

void    init_stack_a(t_stack_node **a, char **argv)
{
    long    n;
    int     i;

    i = 0;
    while (argv[i])
    {
        if (ft_syntax_error(argv[i]))
            free_errors(a);
        n = ft_atol(argv[i]);
        if (n > INT_MAX || n < INT_MIN) //comprobamos si hay overflow
            free_errors(a);
        if (ft_duplicate_error(*a, (int)n))
            free_errors(a);
        ft_append_node(a, (int)n);
        i++;
    }
}

t_stack_node    *ft_get_cheapest(t_stack_node *a)
{
    while (a)
    {
        if (a->cheapest) //si es el mas barato lo devolvemos
            return (a);
        a = a->next;
    }
    return (NULL); 
}

void ft_move_node_to_top(t_stack_node **stack, char stackName)
{
    t_stack_node *cheapest;

    if (!*stack)
        return ;

    cheapest = ft_get_cheapest(*stack); // Encuentra el nodo más barato


    while (*stack != cheapest)  // Rotamos hasta que el nodo más barato esté en la cima
    {
        if (cheapest->above_median) //si esta por encima de la mediana es mas optimo rotate
        {
            if (stackName == 'A')
                ra(stack, false);
            else
                rb(stack, false);
        }
        else //si esta por debajo es mas optimo reverse rotate
        {
            if (stackName == 'A')
                rra(stack, false);
            else
                rrb(stack, false);
        }
    }
}