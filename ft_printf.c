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

static int	ft_puthex_ul_len(unsigned long n)
{
	int	count;
	char	*base;

	base = "0123456789abcdef";
	count = 0;
	if (n > 16)
		count += ft_puthex_ul_len(n / 16);
	count += ft_putchar_len(base[n % 16]);
	return (count);
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


static	int	ft_putptr_len(void *ptr)
{
	unsigned long	addr;
	int	count;

	addr = (unsigned long)ptr;
	if (addr == 0)
		return (write(1,"(nil)",5));
	count = write(1, "0x", 2);
	count += ft_puthex_ul_len(addr);
	return (count);
}

static	int ft_puthex_len(unsigned int n, int upper)
{
	int	count;
	char *base;
	char *uppercase;
	char *lowercase;

	uppercase= "0123456789ABCDEF";
	lowercase = "0123456789abcdef";
	if (upper)
		base = uppercase;
	else
		base = lowercase;
	count = 0;
	if (n >= 16)
		count += ft_puthex_len(n / 16, upper);
	count += ft_putchar_len(base[n % 16]);
	return (count);	
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
	if (spec == 'x')
		count += ft_puthex_len(va_arg(args, int), 0);
	if (spec == 'X')
		count += ft_puthex_len(va_arg(args, int), 1);
	if (spec == 'p')
		count += ft_putptr_len(va_arg(args, void *));
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
	int hexa = 10;

	ft_printf ("there are %d %s jumping obver the sleeping dog and the dog barks %x times at memory %p", count, s, hexa, (void*)&s);

	return 0;

}