/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 19:46:27 by acoupleu          #+#    #+#             */
/*   Updated: 2016/05/31 17:47:24 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_env	env;
	va_list	ap;

	env.i = 0;
	env.n = 0;
	env.conv = ft_strdup("sSpdDioOuUxXcC%");
	va_start(ap, format);
	while (format[env.i])
	{
		if (format[env.i] == '%')
		{
			(env.i)++;
			parse_option(format, &ap, &env);
		}
		else
		{
			ft_putchar(format[env.i]);
			(env.n)++;
		}
		(env.i)++;
	}
	va_end(ap);
	free(env.conv);
	return (env.n);
}
