/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchern-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 11:00:12 by tchern-h          #+#    #+#             */
/*   Updated: 2026/10/17 12:00:00 by tchern-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format_variable(char spec, va_list args)
{
	int	count;

	count = 0;
	if (spec == 'c')
		count += ft_putchar_len(va_arg(args, int));
	if (spec == 's')
		count += ft_putstr_len(va_arg(args, char *));
	if (spec == '%')
		count += ft_putchar_len('%');
	if (spec == 'd' || spec == 'i')
		count += ft_putnbr_len(va_arg(args, int));
	if (spec == 'u')
		count += ft_putnbr_unsigned_len(va_arg(args, unsigned int));
	if (spec == 'x')
		count += ft_puthex_len(va_arg(args, unsigned int), 0);
	if (spec == 'X')
		count += ft_puthex_len(va_arg(args, unsigned int), 1);
	if (spec == 'p')
		count += ft_putptr_len(va_arg(args, void *));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += ft_format_variable(format[i + 1], args);
			i += 2;
		}
		else
		{
			count += ft_putchar_len(format[i]);
			i++;
		}
	}
	va_end(args);
	return (count);
}
