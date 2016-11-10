/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 15:27:52 by acoupleu          #+#    #+#             */
/*   Updated: 2016/03/23 15:56:24 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	if (*s2 == '\0')
		return ((char*)s1);
	while (s1[i] != '\0')
	{
		j = 0;
		while (s2[j] == s1[i + j])
		{
			if (s2[j + 1] == '\0')
			{
				return ((char*)s1 + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
