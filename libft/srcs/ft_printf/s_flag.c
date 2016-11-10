/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 22:28:43 by acoupleu          #+#    #+#             */
/*   Updated: 2016/05/31 12:16:48 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_sminus(char *str, int i, t_flag *f, t_env *env)
{
	int		j;
	int		k;

	j = f->acc;
	k = i;
	if (f->acc != 0 && f->acc < i)
	{
		while (str && (f->acc)-- > 0)
			(env->n) += count_putchar(*str++);
		while (((f->size)-- - j) > 0)
			(env->n) += count_putchar(' ');
	}
	else
	{
		while (str && i-- > 0 && f->acc == 0)
			(env->n) += count_putchar(*str++);
		while (str && i-- >= 0 && ((f->acc)-- - i) > 0)
			(env->n) += count_putchar(*str++);
		while (((f->size)-- - k) > 0)
			(env->n) += count_putchar(' ');
	}
}

void		do_string2(char *str, t_flag *f, t_env *env, int i)
{
	while (((f->size)-- - i) > 0)
		(env->n) += count_putchar(' ');
	while (str && i-- > 0 && f->acc == 0)
		(env->n) += count_putchar(*str++);
	while (str && i-- >= 0 && ((f->acc)-- - i) > 0)
		(env->n) += count_putchar(*str++);
}

void		do_string(char *str, t_flag *f, t_env *env)
{
	int		i;

	if (str == NULL)
	{
		count_putstr(NULL, env);
		return ;
	}
	f->acc = (f->acc == -5) ? 0 : f->acc;
	i = ft_strlen(str);
	if (f->acc < 0)
		while ((f->size)-- > 0)
			(env->n) += count_putchar(' ');
	else if (f->minus == 1)
		print_sminus(str, i, f, env);
	else if (f->acc > 0 && f->acc < i)
	{
		while (((f->size)-- - f->acc) > 0)
			(env->n) += count_putchar(' ');
		while (str && (f->acc)-- > 0)
			(env->n) += count_putchar(*str++);
	}
	else
		do_string2(str, f, env, i);
}
