/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperales <cperales@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 22:00:45 by cperales          #+#    #+#             */
/*   Updated: 2025/05/26 00:30:30 by cperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	execute_operation(char *op, t_stack_node **a, t_stack_node **b)
{
	if (!ft_strncmp(op, "sa", 3))
		sa(a, true);
	else if (!ft_strncmp(op, "sb", 3))
		sb(b, true);
	else if (!ft_strncmp(op, "ss", 3))
		ss(a, b, true);
	else if (!ft_strncmp(op, "pa", 3))
		pa(a, b, true);
	else if (!ft_strncmp(op, "pb", 3))
		pb(b, a, true);
	else if (!ft_strncmp(op, "ra", 3))
		ra(a, true);
	else if (!ft_strncmp(op, "rb", 3))
		rb(b, true);
	else if (!ft_strncmp(op, "rr", 3))
		rr(a, b, true);
	else if (!ft_strncmp(op, "rra", 4))
		rra(a, true);
	else if (!ft_strncmp(op, "rrb", 4))
		rrb(b, true);
	else if (!ft_strncmp(op, "rrr", 4))
		rrr(a, b, true);
	else
		return (0);
	return (1);
}

int	is_sorted(t_stack_node *a)
{
	while (a && a->next)
	{
		if (a->nbr > a->next->nbr)
			return (0);
		a = a->next;
	}
	return (1);
}

void	clear_stdin_line(void)
{
	char	ch;

	while (read(0, &ch, 1) > 0 && ch != '\n')
		;
}

void	read_opps(t_stack_node **a, t_stack_node **b)
{
	char	buffer[5];
	int		read_ret;

	read_ret = read(0, buffer, 4);
	if (read_ret > 4)
		exit (1);
	while (read_ret > 0)
	{
		buffer[read_ret] = '\0';
		if (read_ret > 0 && buffer[read_ret - 1] == '\n')
			buffer[read_ret - 1] = '\0';
		if (!execute_operation(buffer, a, b))
		{
			write(2, "Error\n", 6);
			if (buffer[0] != ' ' && buffer[1] != ' ' && buffer[2] != ' ')
				clear_stdin_line();
			exit (1);
		}
		read_ret = read(0, buffer, 4);
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	init_stack_a(&a, argv + 1);
	read_opps(&a, &b);
	if (is_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
