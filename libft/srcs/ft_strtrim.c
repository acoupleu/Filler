/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 00:53:28 by acoupleu          #+#    #+#             */
/*   Updated: 2016/04/02 19:42:23 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	count;
	size_t	end;
	char	*str;

	i = 0;
	count = 0;
	while (ft_isablank(s[ft_strlen(s) - 1 - i++]))
		count++;
	if (count == ft_strlen(s))
		return (ft_strdup(""));
	end = count;
	i = 0;
	while (ft_isablank(s[i]) && count <= ft_strlen(s))
	{
		count++;
		i++;
	}
	if (!(str = (char *)ft_memalloc(ft_strlen(s) - count + 1)))
		return (NULL);
	count = 0;
	while (s[i] && i < (ft_strlen(s) - end))
		str[count++] = s[i++];
	str[i] = '\0';
	return (str);
}
