/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 16:48:20 by acoupleu          #+#    #+#             */
/*   Updated: 2016/05/31 17:23:10 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_str(unsigned long long n)
{
	int		i;

	i = 0;
	while (n > 0)
	{
		n = n / 8;
		i++;
	}
	return (i);
}

char		*ft_oitoa(unsigned long long n)
{
	char	*str;
	int		i;

	i = len_str(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	i--;
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[i] = (n % 8) + '0';
		n = n / 8;
		i--;
	}
	return (str);
}
