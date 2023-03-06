/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:09:21 by jomirand          #+#    #+#             */
/*   Updated: 2022/12/05 11:40:06 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_numbs(long num)

{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789";
	if (num < 0)
	{
		num *= -1;
		count += ft_print_char('-');
	}
	if (num < 10)
		count += ft_print_char(*(base + num));
	if (num >= 10)
	{
		count += ft_print_numbs(num / 10);
		count += ft_print_numbs(num % 10);
	}
	return (count);
}
