/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_digit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 19:33:04 by hmiso             #+#    #+#             */
/*   Updated: 2020/07/22 19:03:42 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	format_minus(int *i, int *mas, char *simbol, const char *format)
{
	(*i)++;
	mas[1] = 1;
	(*simbol) = ' ';
	while ((format[*i] == '-' || format[*i] == '0')
	&& format[*i] != '\0')
		(*i)++;
}

static void	count_shirina(int *mas, const char *format, int *i)
{
	mas[2] = ft_atoi(&format[*i]);
	(*i) = *i + count_int(mas[2]);
}

char		pars_digit(const char *format, int *i, int *mas, va_list *factor)
{
	char	simbol;

	simbol = ' ';
	if (format[*i] == '0')
	{
		simbol = '0';
		(*i)++;
		if (format[*i] == '-')
			format_minus(&*i, mas, &simbol, format);
		if (format[*i] == '*')
		{
			count_shirina_flag(mas, &*i, &simbol, va_arg(*factor, int));
			mas[0] = 1;
		}
		else if (ft_isdigit(format[*i]))
		{
			mas[2] = ft_atoi(&format[*i]);
			(*i) = *i + count_int(mas[2]);
		}
	}
	else
		count_shirina(mas, format, &*i);
	return (simbol);
}
