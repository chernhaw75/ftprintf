/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchern-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 11:00:12 by tchern-h          #+#    #+#             */
/*   Updated: 2026/10/17 12:00:00 by tchern-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_len(void *ptr)
{
	unsigned long	addr;
	int				count;

	addr = (unsigned long)ptr;
	if (addr == 0)
		return (write(1, "(nil)", 5));
	count = write(1, "0x", 2);
	count += ft_puthex_ul_len(addr);
	return (count);
}
