/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchern-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 11:00:12 by tchern-h          #+#    #+#             */
/*   Updated: 2026/10/01 12:26:36 by tchern-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>

static	int	ft_putchar_len(char c)
{
	write(1, &c, 1);
	return (1);
}

static	int ft_putstr_len(char* str)
{
	int	i;
	
	i = 0;
	if (!str)
	{
		return (write(1, "(null)", 6));
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

static int	ft_putnbr_unsigned_len(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_unsigned_len(n / 10);
	count += ft_putchar_len((n % 10) + '0');
	return (count);
}

static int	ft_putnbr_len(int n)
{
	int count;

	count = 0;
	if (n == -2147483648)
	{
		count += write(1, "-2147483648", 11);
	}
	if (n < 0)
	{
		count += ft_putchar_len('-');
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr_len(n / 10);
	count += ft_putchar_len((n % 10) + '0');
	return (count);
}

static int	ft_putchar(char c)
{
	
	write(1, &c, 1);
	return (1);
}

static	int	ft_format_variable(char spec, va_list args)
{
	int	count;

	count = 0;
	if (spec == 'c')
		count += ft_putchar_len(va_arg(args, int));
	if (spec == 's')
		count += ft_putstr_len(va_arg(args, char *));
	if (spec == '%')
		count += ft_putchar_len('%');
	if (spec == 'd' || spec =='1')
		count += ft_putnbr_len(va_arg(args, int));
	if (spec == 'u')	
		count += ft_putnbr_unsigned_len(va_arg(args, unsigned int));
	if (spec == 'x' || spec =='X')
	{
		char* x_str;
		int	i;

		x_str = ft_itoa(va_arg(args, int));
		i = 0;
		if (spec == 'x')
		{
			while (x_str[i])
			{
				x_str[i] = ft_toupper(x_str[i]);
				i++;
				count++;
			}	
		}	
		else
		{
			while (x_str[i])
			{
				x_str[i] = ft_tolower(x_str[i]);
				i++;
				count++;
			}

		}
	
		count++;
	}
	
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list args;
	int	i;
	int	count;

	va_start(args, format);
	i = 0;
	count = 0;

	while (format[i])
	{
			if (format[i] =='%')
			{
				count += ft_format_variable(format[i+1],  args);
				i += 2;
			}
			else
			{
				count += ft_putchar(format[i]);
				
				i++;
			}	
	}
	va_end(args);
	return (0);
}

int main(int argc, char** argv)
{

	if (argc < 3)
	return 0;

	if (!argv[1])
	return 0;

	int count = 20;
	char *s ="cat";
	int hexa = 3;

	ft_printf ("there are %d %s jumping obver the sleeping dog and the dog barks %x", count, s, hexa);

	return 0;

}