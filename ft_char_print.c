/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 19:24:25 by hmiso             #+#    #+#             */
/*   Updated: 2020/07/22 19:02:18 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_char_print(char simbol_char, int *mas, int *i, char simbol)
{
	if (mas[1] == 0)
	{
		while ((mas[2] - 1) > 0)
		{
			write(1, &simbol, 1);
			mas[2] = mas[2] - 1;
			mas[6] = mas[6] + 1;
		}
		ft_putchar_fd(simbol_char, 1);
		mas[6] = mas[6] + 1;
	}
	else
	{
		ft_putchar_fd(simbol_char, 1);
		mas[6] = mas[6] + 1;
		while ((mas[2] - 1) > 0)
		{
			write(1, &simbol, 1);
			mas[2] = mas[2] - 1;
			mas[6] = mas[6] + 1;
		}
	}
	clear_mas(mas);
	(*i)++;
}
