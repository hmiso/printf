/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 17:03:21 by hmiso             #+#    #+#             */
/*   Updated: 2020/07/22 19:03:21 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		string_keys_own(int *mas, char *string)
{
	while (mas[4] - mas[5] && string[mas[5]] != '\0')
	{
		write(1, &string[mas[5]++], 1);
		mas[6] = mas[6] + 1;
	}
	if ((mas[4] - mas[7]) > 0)
		while (mas[2] - mas[7] > 0)
		{
			write(1, " ", 1);
			mas[2] = mas[2] - 1;
			mas[6] = mas[6] + 1;
		}
	else
		while ((mas[2] - mas[4]) > 0)
		{
			write(1, " ", 1);
			mas[2] = mas[2] - 1;
			mas[6] = mas[6] + 1;
		}
}

static void		string_keys_two(int *mas, char *string)
{
	if ((mas[4] - mas[7]) > 0)
	{
		while (mas[2] - mas[7] > 0)
		{
			write(1, " ", 1);
			mas[2] = mas[2] - 1;
			mas[6] = mas[6] + 1;
		}
	}
	else
	{
		mas[7] = mas[2] - mas[4];
		while (mas[7] > 0)
		{
			write(1, " ", 1);
			mas[7] = mas[7] - 1;
			mas[6] = mas[6] + 1;
		}
	}
	while (mas[4] - mas[5] && string[mas[5]] != '\0')
	{
		write(1, &string[mas[5]++], 1);
		mas[6] = mas[6] + 1;
	}
}

static void		string_keys_thre(int *mas, char *string, char simbol)
{
	mas[7] = ft_strlen(string);
	mas[2] = mas[2] - mas[7];
	while (mas[2] > 0)
	{
		write(1, &simbol, 1);
		mas[2] = mas[2] - 1;
		mas[6] = mas[6] + 1;
	}
	mas[6] = mas[6] + ft_strlen(string);
	ft_putstr_fd(string, 1);
}

static void		string_keys_four(int *mas, char *string, char simbol)
{
	ft_putstr_fd(string, 1);
	mas[6] = mas[6] + ft_strlen(string);
	mas[2] = mas[2] - ft_strlen(string);
	while (mas[2] > 0)
	{
		write(1, &simbol, 1);
		mas[2] = mas[2] - 1;
		mas[6] = mas[6] + 1;
	}
}

void			ft_string_print(char *string, int *mas, int *i, char simbol)
{
	if (string == NULL)
		string = "(null)";
	if (mas[4] > 0 || mas[3] == 1)
	{
		mas[7] = ft_strlen(string);
		if (mas[1] == 1)
			string_keys_own(mas, string);
		else
			string_keys_two(mas, string);
	}
	else if (mas[1] == 0)
		string_keys_thre(mas, string, simbol);
	else
		string_keys_four(mas, string, simbol);
	clear_mas(mas);
	(*i)++;
}
