/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprieur <eprieur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:29:50 by eprieur           #+#    #+#             */
/*   Updated: 2025/11/22 02:17:56 by eprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_nb(long nb)
{
	int	c;

	c = 0;
	while (nb >= 10)
	{
		nb = nb / 10;
		c++;
	}
	return (c + 1);
}

int	ft_putint(int nb)
{
	int	n;
	int	token;

	n = nb;
	token = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
		token += 1;
	}
	if (n >= 10)
		ft_putint(n / 10);
	ft_putchar((n % 10) + '0');
	if (nb < 0)
		nb *= -1;
	return (count_nb(nb) + token);
}
