/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_a_to_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperales <cperales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 21:42:39 by cperales          #+#    #+#             */
/*   Updated: 2025/05/18 09:58:58 by cperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void    ft_current_index(t_stack_node *stack) //inicializa indices y su valor respecto a la mediana
{
    int i;
    int median;

    i = 0;
    if (!stack)
        return ;
    median = stack_len(stack) / 2; //la mediana es la mitad de la longitud
    while (stack)
    {
        stack->index = i;
        if (i <= median)
            stack->above_median = true; //si es menor o igual que la mediana significa que esta por encima
        else
            stack->above_median = false; //si es mayor significa que esta por debajo
        stack = stack->next;
        i++;
    }
}

void    ft_set_target_a(t_stack_node *a, t_stack_node *b) //linkea a a b
{
    t_stack_node *current_b; //usaremos esta variable para poder recorrer b en un doble bucle sin que el b de verdad avance
    t_stack_node *target_node; //aqui guardaremos el nodo objetivo
    long        best_match; //aqui el valor del mas cercano hasta ahora

    while (a)
    {
        best_match = LONG_MIN; //inicializamos en el minimo valor posible para que cualquier numero de b sea un mejor match
        current_b = b;
        while (current_b)
        {
            if (current_b->nbr < a->nbr && current_b->nbr > best_match) //si es menor que a pero mayor que el mejor match hasta ahora
            {
                target_node = current_b; //significa que es el que queremos
                best_match = current_b->nbr;
            }
            current_b = current_b->next; //seguimos el bucle
        }
        if (best_match == LONG_MIN) //si todavia es LONG_MIN (lo que significa que no ha habido ningun numero menor)
            a->target_node = find_max(b); //el target node de A sera el mayor numero de B
        else
            a->target_node = target_node; //si hemos encontrado un numero que se acerque mas lo asignamos al target node de A
        a = a->next; //seguimos el bucle
    }
}

static void ft_cost_analysis_a(t_stack_node *a, t_stack_node *b) //consigue el push cost del stack a
{
    int len_a;
    int len_b;

    len_a = stack_len(a);
    len_b = stack_len(b);
    while (a)
    {
        a->push_cost = a->index; //inicializamos el push_cost de 'a' a su indice
        if (!(a->above_median)) //si a no esta por encima de la mediana
            a->push_cost = len_a - (a->index); //el push_cost sera la longitud del stack menos el indice
        if (a->target_node->above_median) //si b esta por encima de la mediana (y a tambien)
            a->push_cost += a->target_node->index; //el push_cost sera lo que cueste subir a + lo que cueste subir b, recordar que el top del stack tiene indice 0
        else //a encima de la mediana pero b por debajo
            a->push_cost += len_b - (a->target_node->index); //le sumare al push_cost de a lo que nos cuesta subir b
        a = a->next; //seguimos el bucle
    }
}

void    ft_set_cheapest(t_stack_node *stack) //encuentra el push mas barato
{
    long            cheapest; //valor push_cost mas barato
    t_stack_node    *cheapest_node; //nodo mas barato

    if (!stack)
        return ;
    cheapest = LONG_MAX; //inicializamos el valor mas barato como el mayor numero posible para que todo lo que haya en el stack sea mas bajo
    while (stack)
    {
        if (stack->push_cost < cheapest) //si el push cost de nuestro nodo es menor que el mas barato actual
        {
            cheapest = stack->push_cost;
            cheapest_node = stack;
        }
        stack = stack->next;
    }
    cheapest_node->cheapest = true;
}

void    ft_link_a_to_b(t_stack_node *a, t_stack_node *b) //se asegura de cumplir todo para que el push sea el mas barato posible
{
    ft_current_index(a);
    ft_current_index(b);
    ft_set_target_a(a, b);
    ft_cost_analysis_a(a, b);
    ft_set_cheapest(a);
}
