/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 16:48:53 by hmiso             #+#    #+#             */
/*   Updated: 2020/07/22 19:03:30 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		unsig_keys_own(int *mas, long long int u_decimial)
{
	mas[7] = mas[2] - mas[4];
	if (u_decimial < 0)
		mas[7]--;
	while (mas[7] > 0)
	{
		write(1, " ", 1);
		mas[7]--;
		mas[6]++;
	}
	mas[7] = mas[4] - count_int(u_decimial);
	if (u_decimial < 0)
	{
		ft_putchar_fd('-', 1);
		u_decimial = u_decimial * -1;
	}
	while (mas[7] > 0)
	{
		write(1, "0", 1);
		mas[7]--;
		mas[6]++;
	}
	mas[6] = mas[6] + count_int(u_decimial);
	ft_putnbr_fd(u_decimial, 1);
}

static void		unsig_keys_two(int *mas, long long int u_decimial)
{
	mas[7] = mas[4] - count_int(u_decimial);
	if (u_decimial < 0)
	{
		ft_putchar_fd('-', 1);
		u_decimial = u_decimial * -1;
		mas[2]--;
	}
	while (mas[7] > 0)
	{
		write(1, "0", 1);
		mas[7]--;
		mas[6]++;
	}
	ft_putnbr_fd(u_decimial, 1);
	mas[6] = mas[6] + count_int(u_decimial);
	mas[7] = mas[2] - mas[4];
	while (mas[7] > 0)
	{
		write(1, " ", 1);
		mas[7]--;
		mas[6]++;
	}
}

static void		unsig_keys_thre(int *mas, long long int u_decimial,
char *simbol)
{
	if (u_decimial < 0)
		mas[2]--;
	if (mas[7] < 0 && mas[3] == 1)
		(*simbol) = ' ';
	if (u_decimial < 0 && *simbol == '0' && mas[7] < 0)
	{
		ft_putchar_fd('-', 1);
		u_decimial = u_decimial * -1;
	}
	if (mas[7] <= 0 && mas[3] == 1)
		(*simbol) = ' ';
	if (mas[4] == 0 && mas[2] != 0 && mas[3] == 1 && u_decimial == 0)
		mas[2]++;
	while ((mas[2] - count_int(u_decimial)) > 0)
	{
		write(1, &*simbol, 1);
		mas[2]--;
		mas[6]++;
	}
	if (mas[4] != 0 || mas[3] != 1 || u_decimial != 0)
	{
		ft_putnbr_fd(u_decimial, 1);
		mas[6] = mas[6] + count_int(u_decimial);
	}
}

static void		unsig_keys_four(int *mas, long long int u_decimial, char simbol)
{
	if (mas[4] == 0 && mas[2] != 0 && mas[3] == 1 && u_decimial == 0)
		mas[2]++;
	if (mas[4] != 0 || mas[3] != 1)
	{
		ft_putnbr_fd(u_decimial, 1);
		mas[6] = mas[6] + count_int(u_decimial);
	}
	else if (u_decimial != 0)
	{
		ft_putnbr_fd(u_decimial, 1);
		mas[6] = mas[6] + count_int(u_decimial);
	}
	if (mas[4] - count_int(u_decimial) < 0)
		simbol = ' ';
	if (u_decimial < 0)
		mas[2]--;
	while ((mas[2] - count_int(u_decimial)) > 0)
	{
		write(1, &simbol, 1);
		mas[2]--;
		mas[6]++;
	}
}

void			ft_unsigned_print(long long int u_decimial, int *mas, int *i,
char simbol)
{
	mas[7] = mas[4] - count_int(u_decimial);
	if (mas[7] > 0 && mas[4] != 0)
	{
		if (mas[1] == 0)
			unsig_keys_own(mas, u_decimial);
		else
			unsig_keys_two(mas, u_decimial);
	}
	else if (mas[1] == 0)
		unsig_keys_thre(mas, u_decimial, &simbol);
	else
		unsig_keys_four(mas, u_decimial, simbol);
	clear_mas(mas);
	(*i)++;
}
