/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 00:42:14 by acoupleu          #+#    #+#             */
/*   Updated: 2016/03/31 22:32:41 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len_s1_s2;

	len_s1_s2 = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)ft_memalloc(sizeof(char) * (len_s1_s2 + 1));
	if (str == NULL)
		return (NULL);
	ft_strcat(str, s1);
	ft_strcat(str, s2);
	str[len_s1_s2 + 1] = '\0';
	return (str);
}
