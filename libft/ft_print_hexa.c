/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:10:53 by jomirand          #+#    #+#             */
/*   Updated: 2022/12/05 17:43:34 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_hexa(unsigned long num, char c)

{
	int		count;
	char	*base;

	count = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	if (num < 16)
		count += ft_print_char(*(base + num));
	if (num >= 16)
	{
		count += ft_print_hexa(num / 16, c);
		count += ft_print_hexa(num % 16, c);
	}
	return (count);
}
