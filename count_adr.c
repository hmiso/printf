/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_adr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 17:03:52 by hmiso             #+#    #+#             */
/*   Updated: 2020/07/22 19:02:01 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	count_adr(void *str)
{
	long int			div;
	unsigned long int	n;
	int					count;

	count = 2;
	if (str == NULL)
		return (3);
	n = (unsigned long int)str;
	div = 16;
	if (n < 16)
		return (3);
	while (n / div >= 16)
		div *= 16;
	while (div > 0)
	{
		n %= div;
		div /= 16;
		count++;
	}
	return (count);
}
