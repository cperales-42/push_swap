/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperales <cperales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 23:31:03 by cperales          #+#    #+#             */
/*   Updated: 2025/05/18 09:59:27 by cperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int ft_syntax_error(char *str)
{
    if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9'))) //si el primer caracter no es un signo ni un digito dar error
        return (1);
    if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9')) //si el primer caracter es un signo pero el segundo no es un digito dar error
        return (1);
    while (*++str) //si no hay errores hasta aqui, vamos aumentando de caracter en caracter para ver si alguno no es un digito
    {
        if (!(*str >= '0' && *str <= '9')) //si no es un digito dar error
            return (1);
    }
    return (0);
}

int ft_duplicate_error(t_stack_node *a, int n)
{
    if (!a)
        return (0);
    while (a) //mientras exista
    {
        if (a->nbr == n) //si el numero del stack es n dar error
            return (1);
        a = a->next; //comprobar el siguiente
    }
    return (0);
}

void    free_stack(t_stack_node **stack)
{
    t_stack_node    *tmp; //temporal para guardar los enlaces antes de liberar
    t_stack_node    *current;

    if (!stack)
        return ;

    current = *stack;
    while (current) //si hay un nodo en el stack
    {
        tmp = current->next; //asignamos el puntero del siguiente nodo a tmp
        current->nbr = 0; //asignamos el numero a 0 para evitar posibles memory leaks
        free(current); // liberamos el nodo
        current = tmp; // ahora tmp es el primer nodo (conserva enlaces pero no el numero)
    }
    *stack = NULL;
}

void    free_errors(t_stack_node **a)
{
    free_stack(a);
    ft_printf("Error\n");
    exit(1);
}
