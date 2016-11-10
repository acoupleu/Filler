/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 16:39:40 by acoupleu          #+#    #+#             */
/*   Updated: 2016/05/31 19:44:06 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_flag(t_flag *flag)
{
	flag->acc = -5;
	flag->diese = 0;
	flag->etoile = 0;
	flag->size = 0;
	flag->h = 0;
	flag->j = 0;
	flag->l = 0;
	flag->minus = 0;
	flag->plus = 0;
	flag->space = 0;
	flag->z = 0;
	flag->zero = 0;
}

int			parse_option(const char *format, va_list *ap, t_env *env)
{
	t_flag flag;

	init_flag(&flag);
	parse_flag(format, &flag, env);
	if (flag.etoile == 1)
		return (0);
	parse_conv(format, ap, &flag, env);
	return (0);
}

static void	parse_conv2(const char *format, va_list *ap, t_flag *f, t_env *env)
{
	if (format[env->i] == 'U')
		do_uinteger(va_arg(*ap, unsigned long long), f, env, 'U');
	else if (format[env->i] == 'p')
		do_pointer(va_arg(*ap, void*), f, env);
	else if (format[env->i] == '%')
		do_percentage('%', f, env);
}

void		parse_conv(const char *format, va_list *ap, t_flag *f, t_env *env)
{
	if (format[env->i] == 'c' && f->l == 0)
		do_char(va_arg(*ap, int), f, env);
	else if (format[env->i] == 'C' || (format[env->i] == 'c' && f->l == 1))
		do_wchar(va_arg(*ap, wchar_t), f, env);
	else if (format[env->i] == 's' && f->l == 0)
		do_string(va_arg(*ap, char *), f, env);
	else if (format[env->i] == 'S' || (format[env->i] == 's' && f->l == 1))
		do_wstring(va_arg(*ap, wchar_t *), f, env);
	else if (format[env->i] == 'd' || format[env->i] == 'i')
		do_integer(va_arg(*ap, long long), f, env, 'd');
	else if (format[env->i] == 'D')
		do_integer(va_arg(*ap, long long), f, env, 'D');
	else if (format[env->i] == 'x')
		do_lower_hex(va_arg(*ap, unsigned long long), f, env);
	else if (format[env->i] == 'X')
		do_upper_hex(va_arg(*ap, unsigned long long), f, env);
	else if (format[env->i] == 'o')
		do_octal(va_arg(*ap, unsigned long long), f, env, 'o');
	else if (format[env->i] == 'O')
		do_octal(va_arg(*ap, unsigned long long), f, env, 'O');
	else if (format[env->i] == 'u')
		do_uinteger(va_arg(*ap, unsigned long long), f, env, 'u');
	else
		parse_conv2(format, ap, f, env);
}
