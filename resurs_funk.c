/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resurs_funk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 17:15:56 by hmiso             #+#    #+#             */
/*   Updated: 2020/07/22 19:03:47 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			count_int(long long int i)
{
	int count;

	count = 0;
	if (i == 0)
		return (1);
	if (i < 0)
		i = i * -1;
	while (i > 0)
	{
		count++;
		i = i / 10;
	}
	return (count);
}

void		count_tochnost(int *mas, int *i, const char *format)
{
	mas[3] = 1;
	(*i)++;
	if (ft_isdigit(format[*i]))
	{
		if (format[*i] == '0')
			(*i)++;
		if (ft_isdigit(format[*i]))
		{
			mas[4] = ft_atoi(&format[*i]);
			(*i) = *i + count_int(mas[4]);
		}
	}
}

void		count_shirina_flag(int *mas, int *i, char *simbol, int arg)
{
	mas[2] = arg;
	(*i)++;
	if (mas[2] < 0)
	{
		mas[1] = 1;
		mas[2] = mas[2] * -1;
		(*simbol) = ' ';
	}
}

void		pars_format(const char *format, int *mas, int *i)
{
	if (format[*i] == ' ' && format[*i - 2] != '%')
	{
		write(1, " ", 1);
		(*i)++;
		mas[0] = 1;
	}
	if (format[*i] == '-')
	{
		(*i)++;
		mas[1] = 1;
		while ((format[*i] == '-' || format[*i] == '0') && format[*i] != '\0')
			(*i)++;
	}
}

void		clear_mas(int *mas)
{
	mas[0] = 0;
	mas[1] = 0;
	mas[2] = 0;
	mas[3] = 0;
	mas[4] = 0;
	mas[5] = 0;
	mas[7] = 0;
	mas[8] = 0;
}
