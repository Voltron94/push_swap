/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voltron <voltron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:25:13 by eprieur           #+#    #+#             */
/*   Updated: 2025/12/12 21:35:00 by voltron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	testformat(const char *s, va_list args, int *c)
{
	int	i;

	i = 0;
	if (s[i] == '%' && s[i + 1] == 'c')
		*c = *c + ft_putchar(va_arg(args, int));
	else if (s[i] == '%' && s[i + 1] == 's')
		*c = *c + ft_putstr(va_arg(args, char *));
	else if (s[i] == '%' && (s[i + 1] == 'i' || s[i + 1] == 'd'))
		*c = *c + ft_putint(va_arg(args, int));
	else if (s[i] == '%' && s[i + 1] == 'u')
		*c = *c + ft_putchar('%');
	else
		return (0);
	return (1);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	if (!s)
		return (-1);
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%' && testformat(&s[i], args, &count))
			i++;
		else if (!(testformat(&s[i], args, &count)))
		{
			ft_putchar(s[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
