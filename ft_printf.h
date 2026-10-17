/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchern-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 11:00:12 by tchern-h          #+#    #+#             */
/*   Updated: 2026/10/17 12:00:00 by tchern-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar_len(char c);
int	ft_putstr_len(char *str);
int	ft_putnbr_len(int n);
int	ft_putnbr_unsigned_len(unsigned int n);
int	ft_puthex_len(unsigned int n, int upper);
int	ft_puthex_ul_len(unsigned long n);
int	ft_putptr_len(void *ptr);

#endif
