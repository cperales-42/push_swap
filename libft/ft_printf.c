/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperales <cperales@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:29:25 by cperales          #+#    #+#             */
/*   Updated: 2025/05/25 04:09:49 by cperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_pf(char c, int *counter)
{
	write(1, &c, 1);
	(*counter)++;
}

void	ft_print_pf(char *fmt, int *counter, va_list arglst)
{
	if (*fmt == 'c')
		ft_putchar_pf(va_arg(arglst, int), counter);
	else if (*fmt == '%')
		ft_putchar_pf('%', counter);
	else if (*fmt == 's')
		ft_putstr_pf(va_arg(arglst, char *), counter);
	else if (*fmt == 'i' || *fmt == 'd')
		ft_putnbr_pf(va_arg(arglst, int), counter);
	else if (*fmt == 'u')
		ft_putu_pf(va_arg(arglst, unsigned int), counter);
	else if (*fmt == 'x' || *fmt == 'X')
		ft_puthex_pf(va_arg(arglst, unsigned int), counter, *fmt);
	else if (*fmt == 'p')
		ft_putptr(va_arg(arglst, void *), counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	arglst;
	int		counter;
	char	*fmt;

	counter = 0;
	fmt = (char *)format;
	va_start(arglst, format);
	while (*fmt)
	{
		if (*fmt != '%')
			ft_putchar_pf(*fmt, &counter);
		else
		{
			fmt++;
			if (*fmt)
				ft_print_pf(fmt, &counter, arglst);
		}
		fmt++;
	}
	va_end(arglst);
	return (counter);
}

/*int main()
{
	int i = 42, j = 14	;
	char *s;

	s = "Hola Mundo";
	j = ft_printf("%s  %d  %p  %x  %X", s, i, &i, j, j);
	printf("\n %d \n", j);
	return 0;
}*/
