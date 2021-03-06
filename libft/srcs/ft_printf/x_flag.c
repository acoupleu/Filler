/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 20:35:11 by acoupleu          #+#    #+#             */
/*   Updated: 2016/05/31 19:25:44 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_sign(char *hex, t_flag *f, t_env *env)
{
	if (f->diese == 1 && ft_strcmp(hex, "0"))
		count_putstr("0x", env);
}

static void	print_nminus(char *hex, int len, t_flag *f, t_env *env)
{
	int sign;

	sign = 0;
	if (f->diese > 0 && ft_strcmp(hex, "0"))
		f->size = f->size - 2;
	if (f->acc == -5 && f->zero == 1)
	{
		check_sign(hex, f, env);
		sign = 1;
	}
	while (f->size > len && f->size-- > f->acc)
		f->acc == -5 && f->zero == 1 ?
		((env->n) += count_putchar('0')) : ((env->n) += count_putchar(' '));
	sign == 0 ? check_sign(hex, f, env) : 0;
	f->acc == -1 && ft_strcmp(hex, "0") == 0 && f->diese == 0 ?
	(env->n) += count_putchar(' ') : 0;
	if (f->acc == -1 && ft_strcmp(hex, "0") == 0)
		return ;
	while ((f->acc)-- > len)
		(env->n) += count_putchar('0');
	count_putstr(hex, env);
}

static void	print_minus(char *hex, int len, t_flag *f, t_env *env)
{
	if (f->diese > 0 && ft_strcmp(hex, "0"))
		f->size = f->size - 2;
	check_sign(hex, f, env);
	while ((f->acc)-- > len)
	{
		(env->n) += count_putchar('0');
		(f->size)--;
	}
	f->size = f->size - len;
	if (f->acc == -2 && ft_strcmp(hex, "0") == 0)
	{
		while ((f->size)-- > 0)
			(env->n) += count_putchar(' ');
		return ;
	}
	count_putstr(hex, env);
	while ((f->size)-- > 0)
		(env->n) += count_putchar(' ');
}

void		do_lower_hex(unsigned long long d, t_flag *f, t_env *env)
{
	int		len;
	char	*hex;

	d = conv_oux(d, f);
	hex = ft_xitoa(d);
	len = ft_strlen(hex);
	if (f->acc == -1 && f->size == 0 && d == 0)
		return ;
	else if (f->minus == 1 && f->size > f->acc)
		print_minus(hex, len, f, env);
	else
		print_nminus(hex, len, f, env);
	free(hex);
}
