/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 17:07:22 by acoupleu          #+#    #+#             */
/*   Updated: 2016/05/31 19:45:25 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include "libft.h"

typedef struct		s_env
{
	int		i;
	int		n;
	char	*conv;
}					t_env;

typedef struct		s_flag
{
	int	acc;
	int	diese;
	int	etoile;
	int	size;
	int	h;
	int	j;
	int	l;
	int	minus;
	int	plus;
	int	space;
	int	z;
	int	zero;
}					t_flag;

typedef struct		s_ws
{
	int		w_acc;
	int		w_len;
	int		w_strlen;
	int		w_strlenini;
}					t_ws;

/*
** print_flag
*/

int					count_wputchar(wchar_t c);
int					count_putchar(char c);
void				count_putnbr(long long nbr, t_env *env);
void				count_putstr(char *str, t_env *env);
int					count_putwchar(wchar_t arg, int i);

/*
** parsing
*/

void				parse_accuracy(const char *format,
									t_flag *flag, t_env *env);
void				parse_conv(const char *format,
								va_list *ap, t_flag *f, t_env *env);
void				parse_flag(const char *format, t_flag *flag, t_env *env);
int					parse_option(const char *format, va_list *ap, t_env *env);
void				parse_size(const char *format, t_flag *flag, t_env *env);

/*
** do_flag
*/

void				do_char(int c, t_flag *flag, t_env *env);
void				do_integer(long long d, t_flag *f, t_env *env, char c);
void				do_lower_hex(unsigned long long d, t_flag *f, t_env *env);
void				do_octal(unsigned long long d,
								t_flag *f, t_env *env, char c);
void				do_percentage(int ch, t_flag *flag, t_env *env);
void				do_pointer(void *number, t_flag *flag, t_env *env);
void				do_string(char *str, t_flag *f, t_env *env);
void				do_uinteger(unsigned long long d,
								t_flag *f, t_env *env, char c);
void				do_upper_hex(unsigned long long d, t_flag *f, t_env *env);
void				do_wchar(wchar_t arg, t_flag *f, t_env *env);
void				do_wstring(wchar_t *str, t_flag *f, t_env *env);

/*
** tools
*/

long long			conv_d(long long d, t_flag *f);
unsigned long long	conv_oux(unsigned long long d, t_flag *f);
int					i_len(long long n);
char				*str_toupper(char *s);
int					ft_wlen(wchar_t arg);

/*
** THE FUCKING MASTER FONCTION
*/

int					ft_printf(const char *format, ...);

#endif
