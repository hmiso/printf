/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 16:27:40 by hmiso             #+#    #+#             */
/*   Updated: 2020/07/22 19:02:08 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	count_hex(long long int n)
{
	long int			div;
	int					count;

	count = 0;
	div = 16;
	if (n < 16)
		return (1);
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
