/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copyhexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemmoun <akemmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:14:44 by akemmoun          #+#    #+#             */
/*   Updated: 2024/11/24 11:45:39 by akemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_copyhexa(unsigned long int n, const char specifier)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_copyhexa(n / 16, specifier);
	if ((n % 16) <= 9)
		count += ft_putchar((n % 16) + 48);
	else
	{
		if (specifier == 'x')
			count += ft_putchar((n % 16) - 10 + 'a');
		else if (specifier == 'X')
			count += ft_putchar((n % 16) - 10 + 'A');
	}
	return (count);
}
