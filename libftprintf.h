/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 14:25:25 by hmiso             #+#    #+#             */
/*   Updated: 2020/07/22 19:11:02 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

size_t			ft_strlen(const char *s);
int				ft_isdigit(int c);
int				ft_atoi(const char *s1);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(long long int n, int fd);
void			ft_putaddr_fd(void *str, int fd);
void			ft_decimail_print(int decimail, int *mas, int *i, char simbol);
void			ft_unsigned_print(long long int u_decimial, int *mas,
int *i, char simbol);
void			ft_procent_print(int *mas, int *i, char simbol);
void			ft_string_print(char *string, int *mas, int *i, char simbol);
void			ft_char_print(char simbol_char, int *mas, int *i, char simbol);
void			ft_pointer_print(char *string, int *mas, int *i, char simbol);
void			ft_heks_print(long long int u_decimial, int *mas,
int *i, char simbol);
void			ft_putstr_fd(char *s, int fd);
void			ft_putaddr_fd(void *str, int fd);
int				count_hex(long long int n);
int				count_adr(void *str);
void			ft_putnbr_fd(long long int n, int fd);
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
int				count_int(long long int i);
char			pars_digit(const char *format, int *i,
int *mas, va_list *factor);
void			count_shirina_flag(int *mas, int *i, char *simbol, int arg);
void			count_tochnost(int *mas, int *i, const char *format);
void			count_shirina_flag(int *mas, int *i, char *simbol, int arg);
void			pars_format(const char *format, int *mas, int *i);
void			clear_mas(int *mas);
void			ft_puthex(long long int n, int x);
void			heks_keys_own(long long int u_decimial, int *mas,
char simbol, int t);
void			heks_keys_two(long long int u_decimial, int *mas, int t);
void			heks_keys_thre(long long int u_decimial, int *mas, int t);
void			heks_keys_four(long long int u_decimial, int *mas,
char simbol, int t);
void			heks_keys_five(long long int u_decimial, int *mas,
char simbol, int t);

#endif
