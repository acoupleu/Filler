/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 15:19:20 by acoupleu          #+#    #+#             */
/*   Updated: 2016/03/25 00:55:49 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str1;
	char	*str2;

	i = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	if (str2[0] == '\0')
		return (str1);
	while (str1[i] && i < len)
	{
		j = 0;
		while (str1[i + j] && str2[j] && str1[i + j] == str2[j] && i + j < len)
		{
			j++;
			if (str2[j] == '\0' && i < len)
				return (&str1[i]);
		}
		i++;
	}
	return (NULL);
}
