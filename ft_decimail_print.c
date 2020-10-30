/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimail_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 15:57:28 by hmiso             #+#    #+#             */
/*   Updated: 2020/07/22 19:02:31 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		decimail_keys_own(int *mas, int decimail)
{
	mas[7] = mas[2] - mas[4];
	if (decimail < 0)
		mas[7] = mas[7] - 1;
	while (mas[7] > 0)
	{
		write(1, " ", 1);
		mas[7] = mas[7] - 1;
		mas[6] = mas[6] + 1;
	}
	mas[7] = mas[4] - count_int(decimail);
	if (decimail < 0)
	{
		ft_putchar_fd('-', 1);
		decimail = decimail * -1;
	}
	while (mas[7] > 0)
	{
		write(1, "0", 1);
		mas[7] = mas[7] - 1;
		mas[6] = mas[6] + 1;
	}
	mas[6] = mas[6] + count_int(decimail);
	ft_putnbr_fd(decimail, 1);
}

static void		decimail_keys_two(int *mas, int decimail)
{
	mas[7] = mas[4] - count_int(decimail);
	if (decimail < 0)
	{
		ft_putchar_fd('-', 1);
		decimail = decimail * -1;
		mas[2] = mas[2] - 1;
	}
	while (mas[7] > 0)
	{
		write(1, "0", 1);
		mas[7] = mas[7] - 1;
		mas[6] = mas[6] + 1;
	}
	ft_putnbr_fd(decimail, 1);
	mas[6] = mas[6] + count_int(decimail);
	mas[7] = mas[2] - mas[4];
	while (mas[7] > 0)
	{
		write(1, " ", 1);
		mas[7] = mas[7] - 1;
		mas[6] = mas[6] + 1;
	}
}

static void		decimail_keys_thre(int *mas, int decimail, char *simbol)
{
	if (decimail < 0 && *simbol == '0' && mas[7] < 0 && decimail != -2147483648)
	{
		ft_putchar_fd('-', 1);
		decimail = decimail * -1;
	}
	if (mas[4] == 0 && mas[2] != 0 && mas[3] == 1 && decimail == 0)
		mas[2]++;
	mas[7] = mas[2] - count_int(decimail);
	while (mas[7] > 0)
	{
		write(1, &*simbol, 1);
		mas[7] = mas[7] - 1;
		mas[6] = mas[6] + 1;
	}
	if (mas[4] != 0 || mas[3] != 1)
	{
		ft_putnbr_fd(decimail, 1);
		mas[6] = mas[6] + count_int(decimail);
	}
	else if (mas[4] == 0 && mas[3] == 1 && decimail != 0)
	{
		ft_putnbr_fd(decimail, 1);
		mas[6] = mas[6] + count_int(decimail);
	}
}

static void		decimail_keys_four(int *mas, int decimail, char simbol)
{
	if (mas[4] == 0 && mas[2] != 0 && mas[3] == 1 && decimail == 0)
		mas[2]++;
	if (mas[4] != 0 || mas[3] != 1)
	{
		ft_putnbr_fd(decimail, 1);
		mas[6] = mas[6] + count_int(decimail);
	}
	else if (decimail != 0)
	{
		ft_putnbr_fd(decimail, 1);
		mas[6] = mas[6] + count_int(decimail);
	}
	if (mas[4] - count_int(decimail) < 0)
		simbol = ' ';
	if (decimail < 0)
		mas[2] = mas[2] - 1;
	while (((mas[2] - count_int(decimail)) > 0))
	{
		write(1, &simbol, 1);
		mas[2] = mas[2] - 1;
		mas[6] = mas[6] + 1;
	}
}

void			ft_decimail_print(int decimail, int *mas, int *i, char simbol)
{
	mas[7] = mas[4] - count_int(decimail);
	if (decimail < 0)
		mas[6] = mas[6] + 1;
	if (mas[7] > 0 && mas[4] != 0)
	{
		if (mas[1] == 0)
			decimail_keys_own(mas, decimail);
		else
			decimail_keys_two(mas, decimail);
	}
	else if (mas[1] == 0 || (mas[1] == 1 && mas[4] == 0 && mas[2] == 0))
	{
		if (decimail < 0)
			mas[2] = mas[2] - 1;
		if (mas[7] <= 0 && mas[3] == 1)
			simbol = ' ';
		decimail_keys_thre(mas, decimail, &simbol);
	}
	else
		decimail_keys_four(mas, decimail, simbol);
	clear_mas(mas);
	(*i)++;
}
