/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:54:41 by hmiso             #+#    #+#             */
/*   Updated: 2020/07/22 19:03:06 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		resurs_hex(long int div, char temp, long long int n, int x)
{
	div = 16;
	while (n / div >= 16)
		div *= 16;
	while (div > 0)
	{
		temp = '0' + n / div;
		if (temp > '9')
		{
			if (x == 'x')
				temp += 39;
			if (x == 'X')
				temp += 7;
			write(1, &temp, 1);
		}
		else
			write(1, &temp, 1);
		n %= div;
		div /= 16;
	}
}

void			ft_puthex(long long int n, int x)
{
	long int			div;
	char				temp;

	temp = '0';
	div = 0;
	if (n < 10)
	{
		temp = '0' + n;
		write(1, &temp, 1);
	}
	else if (n < 16)
	{
		temp = '0' + n;
		if (x == 'x')
			temp += 39;
		if (x == 'X')
			temp += 7;
		write(1, &temp, 1);
	}
	else
		resurs_hex(div, temp, n, x);
}
