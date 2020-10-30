/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 15:57:28 by hmiso             #+#    #+#             */
/*   Updated: 2020/07/22 19:02:43 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		pointer_keys_own(int *mas, char *string, char simbol)
{
	mas[2] = mas[2] - count_adr(string) + 1;
	while (mas[2] > 0)
	{
		write(1, &simbol, 1);
		mas[2] = mas[2] - 1;
		mas[6] = mas[6] + 1;
	}
	mas[6] = mas[6] + 2;
	write(1, "0x", 2);
}

static void		pointer_keys_two(int *mas, char *string, char simbol)
{
	if (string == NULL)
		mas[2] = mas[2] - 3;
	else
		mas[2] = mas[2] - count_adr(string);
	while (mas[2] > 0)
	{
		write(1, &simbol, 1);
		mas[2] = mas[2] - 1;
		mas[6] = mas[6] + 1;
	}
	mas[6] = mas[6] + count_adr(string);
	ft_putaddr_fd(string, 1);
}

void			ft_pointer_print(char *string, int *mas, int *i, char simbol)
{
	if (string == NULL && mas[3] == 1 && mas[4] == 0)
		pointer_keys_own(mas, string, simbol);
	else if (mas[1] == 0)
		pointer_keys_two(mas, string, simbol);
	else
	{
		ft_putaddr_fd(string, 1);
		mas[6] = mas[6] + count_adr(string);
		mas[2] = mas[2] - count_adr(string);
		while (mas[2] > 0)
		{
			write(1, &simbol, 1);
			mas[2] = mas[2] - 1;
			mas[6] = mas[6] + 1;
		}
	}
	(*i)++;
	clear_mas(mas);
	string = "";
}
