/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 16:32:53 by acoupleu          #+#    #+#             */
/*   Updated: 2016/03/31 22:36:14 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ch;

	ch = NULL;
	while (*s)
	{
		if (*s == c)
			ch = (char *)s;
		s++;
	}
	if (*s == c)
		ch = (char *)s;
	return (ch);
}
