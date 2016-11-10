/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:00:45 by acoupleu          #+#    #+#             */
/*   Updated: 2016/05/31 17:32:20 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	len_str(unsigned long long n)
{
	int		i;

	i = 0;
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

char		*ft_xitoa(unsigned long long n)
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
		if ((n % 16) >= 10)
			str[i] = (n % 16) - 10 + 'a';
		else
			str[i] = (n % 16) + '0';
		n = n / 16;
		i--;
	}
	return (str);
}
