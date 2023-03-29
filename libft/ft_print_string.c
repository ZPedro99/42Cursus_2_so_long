/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:02:02 by jomirand          #+#    #+#             */
/*   Updated: 2022/12/05 14:28:21 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_string(char *str)

{
	int	count;

	count = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (*(str + count))
	{
		write(1, (str + count), 1);
		count++;
	}
	return (count);
}
