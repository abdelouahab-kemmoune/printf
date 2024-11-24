/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemmoun <akemmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:27:18 by akemmoun          #+#    #+#             */
/*   Updated: 2024/11/24 11:25:53 by akemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_format(char specifier, va_list ap)
{
	int		count;

	count = 0;
	if (specifier == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (specifier == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (specifier == 'u')
		count += ft_putnbr2(va_arg(ap, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		count += ft_copyhexa(va_arg(ap, unsigned long int), specifier);
	else if (specifier == 'p')
		count += ft_copyadd(va_arg(ap, void *));
	else if (specifier == '%')
		ft_putchar('%');
	else
	{
		ft_putchar('%');
		ft_putchar(specifier);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	ap;

	if (!format)
		return (-1);
	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format)
				count += print_format(*format, ap);
			else
				return (-1);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}
// #include <stdio.h>
// int main ()
// {
//  	void *p = "test";
//  ft_printf("%u----%x----%X---l%d----%p\n", -107553, 38535, -30765, -8373, p);
//  ft_printf("%u----%x----%X---l%d----%p\n", -107553, 38535, -30765, -8373, p);

// }