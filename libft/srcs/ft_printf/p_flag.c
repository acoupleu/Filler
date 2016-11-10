/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 19:37:48 by acoupleu          #+#    #+#             */
/*   Updated: 2016/05/31 17:49:44 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	do_pointer(void *number, t_flag *flag, t_env *env)
{
	char	*nbr;

	nbr = ft_xitoa((unsigned long long)number);
	if (flag->minus == 1)
	{
		count_putstr("0x", env);
		count_putstr(nbr, env);
		flag->size -= ft_strlen(nbr) + 1;
		while (flag->size-- > 1)
			(env->n) += count_putchar(' ');
	}
	else
	{
		flag->size -= ft_strlen(nbr) + 1;
		while (flag->size-- > 1)
			(env->n) += count_putchar(' ');
		count_putstr("0x", env);
		count_putstr(nbr, env);
	}
	free(nbr);
}
