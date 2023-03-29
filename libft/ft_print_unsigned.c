/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:10:15 by jomirand          #+#    #+#             */
/*   Updated: 2022/12/05 16:14:58 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_unsigned(unsigned int num)

{
	int		count;

	count = 0;
	if (num < 10)
		count += ft_print_char(num + '0');
	if (num >= 10)
	{
		count += ft_print_unsigned(num / 10);
		count += ft_print_unsigned(num % 10);
	}
	return (count);
}
