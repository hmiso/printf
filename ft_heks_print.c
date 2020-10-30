/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heks_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 15:57:28 by hmiso             #+#    #+#             */
/*   Updated: 2020/07/22 19:02:36 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_heks_print(long long int u_decimial, int *mas,
int *i, char simbol)
{
	int t;

	t = mas[8];
	if (mas[4] > 0)
		if (mas[1] == 0 && mas[4] > 0)
			heks_keys_own(u_decimial, mas, simbol, t);
		else if (mas[4] < 0 && simbol == '0')
			heks_keys_two(u_decimial, mas, t);
		else
			heks_keys_thre(u_decimial, mas, t);
	else if (mas[1] == 0)
		heks_keys_four(u_decimial, mas, simbol, t);
	else
		heks_keys_five(u_decimial, mas, simbol, t);
	clear_mas(mas);
	(*i)++;
}
