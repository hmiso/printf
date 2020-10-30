/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 18:05:41 by hmiso             #+#    #+#             */
/*   Updated: 2020/10/30 11:44:34 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char			start_pars(int *i, const char *format,
int *mas, va_list *factor)
{
	char		simbol;

	simbol = ' ';
	(*i)++;
	pars_format(format, mas, &*i);
	if (format[*i] == '*')
		count_shirina_flag(mas, &*i, &simbol, va_arg(*factor, int));
	if (ft_isdigit(format[*i]))
		simbol = pars_digit(format, &*i, mas, &*factor);
	if (format[*i] == '.')
		count_tochnost(mas, &*i, format);
	if (format[*i] == '*')
	{
		mas[4] = va_arg(*factor, int);
		(*i)++;
		if (mas[4] < 0)
			mas[3] = 0;
	}
	return (simbol);
}

static void			print_simbol(const char *format, int *i, int *mas)
{
	ft_putchar_fd(format[*i], 1);
	(*i)++;
	mas[6] = mas[6] + 1;
}

static char			print_start(int *i, const char *format,
int *mas, va_list *factor)
{
	char		simbol;

	simbol = start_pars(&*i, format, mas, &*factor);
	if (format[*i] == 'd' || format[*i] == 'i')
		ft_decimail_print(va_arg(*factor, int), mas, &*i, simbol);
	else if (format[*i] == 'u')
		ft_unsigned_print(va_arg(*factor, unsigned int), mas, &*i, simbol);
	else if (format[*i] == 's' && mas[0] != 1)
		ft_string_print(va_arg(*factor, char *), mas, &*i, simbol);
	else if (format[*i] == 'c')
		ft_char_print(va_arg(*factor, int), mas, &*i, simbol);
	else if (format[*i] == '%')
		ft_procent_print(mas, &*i, simbol);
	else if (format[*i] == 'p')
		ft_pointer_print(va_arg(*factor, char *), mas, &*i, simbol);
	else if (format[*i] == 'x' || format[*i] == 'X')
	{
		mas[8] = format[*i];
		ft_heks_print(va_arg(*factor, unsigned int),
		mas, &*i, simbol);
	}
	return (simbol);
}

int					ft_printf(const char *format, ...)
{
	int			i;
	char		simbol;
	int			mas[9];
	va_list		factor;

	va_start(factor, format);
	i = 0;
	while (i < 9)
	{
		mas[i] = 0;
		i++;
	}
	i = 0;
	while (format[i] != '\0')
		if (format[i] == '%')
			simbol = print_start(&i, format, mas, &factor);
		else
			print_simbol(format, &i, mas);
	va_end(factor);
	return (mas[6]);
}
