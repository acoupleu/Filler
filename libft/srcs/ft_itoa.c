/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 20:29:25 by acoupleu          #+#    #+#             */
/*   Updated: 2016/05/18 20:02:58 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	i_len(int n)
{
	int	lenght;

	if (n == 0)
		return (1);
	lenght = 0;
	if (n < 0)
	{
		lenght++;
		n = ft_abs(n);
	}
	while (n != 0)
	{
		lenght++;
		n /= 10;
	}
	return (lenght);
}

char		*ft_itoa(int n)
{
	char	*nbstr;
	int		sign;
	int		i;

	if (n == 0)
		return (ft_strdup("0"));
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(nbstr = (char *)ft_memalloc(i_len(n) + 1)))
		return (NULL);
	sign = 1;
	if (n < 0)
		sign = -1;
	i = i_len(n);
	n = ft_abs(n);
	nbstr[i] = '\0';
	i--;
	while (n != 0)
	{
		nbstr[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	(sign == -1) ? nbstr[i] = '-' : ' ';
	return (nbstr);
}
