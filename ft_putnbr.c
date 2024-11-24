/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemmoun <akemmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:52:54 by akemmoun          #+#    #+#             */
/*   Updated: 2024/11/22 14:25:05 by akemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		count += ft_putnbr(n / 10);
	count += ft_putchar((n % 10) + 48);
	return (count);
}

int	ft_putnbr2(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		count += ft_putchar('0');
		return (count);
	}
	if (n > 9)
		count += ft_putnbr2(n / 10);
	count += ft_putchar((n % 10) + 48);
	return (count);
}
