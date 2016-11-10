/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 00:07:25 by acoupleu          #+#    #+#             */
/*   Updated: 2016/03/25 03:26:19 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	count;
	size_t	i;

	if (s && f)
	{
		i = 0;
		count = 0;
		if (!(str = (char*)malloc(sizeof(char) * ft_strlen(s) + 1)))
			return (NULL);
		while (s[i])
		{
			str[i] = (char)f(count++, s[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
