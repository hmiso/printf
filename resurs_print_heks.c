/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resurs_print_heks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 13:49:24 by hmiso             #+#    #+#             */
/*   Updated: 2020/07/22 19:03:52 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		heks_keys_own(long long int u_decimial,
int *mas, char simbol, int t)
{
	if (mas[4] > count_hex(u_decimial))
		mas[7] = mas[2] - mas[4];
	else
		mas[7] = mas[2] - count_hex(u_decimial);
	if (mas[4] < 0 && simbol == '0')
	{
		write(1, "0", 1);
		mas[7] = mas[7] - 1;
		mas[4] = mas[4] * -1;
	}
	while (mas[7] > 0)
	{
		write(1, " ", 1);
		mas[7] = mas[7] - 1;
		mas[6] = mas[6] + 1;
	}
	mas[7] = mas[4] - count_hex(u_decimial);
	while (mas[7] > 0)
	{
		write(1, "0", 1);
		mas[7] = mas[7] - 1;
		mas[6] = mas[6] + 1;
	}
	ft_puthex(u_decimial, t);
	mas[6] = mas[6] + count_hex(u_decimial);
}

void		heks_keys_two(long long int u_decimial, int *mas, int t)
{
	mas[7] = mas[2] - count_hex(u_decimial);
	while (mas[7] > 0)
	{
		write(1, "0", 1);
		mas[7] = mas[7] - 1;
		mas[6] = mas[6] + 1;
	}
	ft_puthex(u_decimial, t);
	mas[6] = mas[6] + count_hex(u_decimial);
}

void		heks_keys_thre(long long int u_decimial, int *mas, int t)
{
	mas[7] = mas[4] - count_hex(u_decimial);
	while (mas[7] > 0)
	{
		write(1, "0", 1);
		mas[7] = mas[7] - 1;
		mas[6] = mas[6] + 1;
	}
	ft_puthex(u_decimial, t);
	mas[6] = mas[6] + count_hex(u_decimial);
	if (mas[4] > count_hex(u_decimial))
		mas[7] = mas[2] - mas[4];
	else
		mas[7] = mas[2] - count_hex(u_decimial);
	while (mas[7] > 0)
	{
		write(1, " ", 1);
		mas[7] = mas[7] - 1;
		mas[6] = mas[6] + 1;
	}
}

void		heks_keys_four(long long int u_decimial, int *mas,
char simbol, int t)
{
	if (mas[7] <= 0 && mas[3] == 1)
		simbol = ' ';
	if (mas[4] == 0 && mas[3] == 1 && u_decimial == 0)
		mas[7] = mas[2];
	else
		mas[7] = mas[2] - count_hex(u_decimial);
	while (mas[7] > 0)
	{
		write(1, &simbol, 1);
		mas[7] = mas[7] - 1;
		mas[6] = mas[6] + 1;
	}
	if (mas[4] != 0 || mas[3] != 1 || u_decimial != 0)
	{
		ft_puthex(u_decimial, t);
		mas[6] = mas[6] + count_hex(u_decimial);
	}
}

void		heks_keys_five(long long int u_decimial, int *mas,
char simbol, int t)
{
	if (mas[4] == 0 && mas[3] == 1 && u_decimial == 0)
		mas[7] = mas[2];
	else
	{
		ft_puthex(u_decimial, t);
		mas[6] = mas[6] + count_hex(u_decimial);
		mas[7] = mas[2] - count_hex(u_decimial);
	}
	while (mas[7] > 0)
	{
		write(1, &simbol, 1);
		mas[7] = mas[7] - 1;
		mas[6] = mas[6] + 1;
	}
}
