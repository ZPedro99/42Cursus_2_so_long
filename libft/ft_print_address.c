/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:11:17 by jomirand          #+#    #+#             */
/*   Updated: 2022/12/05 15:25:11 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_address(unsigned long num)

{
	int	count;

	count = 0;
	if (!num)
		return (write(1, "(nil)", 5));
	write (1, "0x", 2);
	count += ft_print_hexa(num, 'x');
	return (count + 2);
}
