/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 18:26:51 by acoupleu          #+#    #+#             */
/*   Updated: 2016/05/31 19:26:42 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		do_char(int ch, t_flag *flag, t_env *env)
{
	if (flag->minus == 1)
	{
		(env->n) += count_putchar(ch);
		while (flag->size-- > 1)
			(env->n) += count_putchar(' ');
	}
	else
	{
		while (flag->size-- > 1)
			(env->n) += count_putchar(' ');
		(env->n) += count_putchar(ch);
	}
}
