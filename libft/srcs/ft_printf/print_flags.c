/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 15:01:04 by acoupleu          #+#    #+#             */
/*   Updated: 2016/06/01 18:02:58 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		count_wputchar(wchar_t c)
{
	write(1, &c, 1);
	return (1);
}

void	count_putstr(char *str, t_env *env)
{
	if (str)
	{
		write(1, str, ft_strlen(str));
		(env->n) += ft_strlen(str);
	}
	else
	{
		write(1, "(null)", 6);
		(env->n) += 6;
	}
}

void	count_putnbr(long long nbr, t_env *env)
{
	long long x;

	if (nbr == -9223372036854775807)
	{
		ft_putstr("-9223372036854775807");
		(env->n) += 11;
		return ;
	}
	x = nbr;
	if (nbr < 0)
	{
		ft_putchar('-');
		(env->n)++;
		x = -nbr;
	}
	if (x >= 10)
	{
		count_putnbr(x / 10, env);
		count_putnbr(x % 10, env);
	}
	else
	{
		ft_putchar(x + '0');
		(env->n)++;
	}
}
