/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copyadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemmoun <akemmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:51:49 by akemmoun          #+#    #+#             */
/*   Updated: 2024/11/22 15:30:07 by akemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_copyadd(void *ptr)
{
	int					count;
	unsigned long int	address;

	if (!ptr)
		return (ft_putstr("(nil)"));
	count = 0;
	address = (unsigned long int)ptr;
	count += ft_putstr("0x");
	count += ft_copyhexa(address, 'x');
	return (count);
}
