/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 21:22:10 by acoupleu          #+#    #+#             */
/*   Updated: 2016/03/24 21:16:45 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	i = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size > dstlen + 1)
	{
		while (i < (size - dstlen - 1))
		{
			dst[i + dstlen] = src[i];
			i++;
		}
		dst[dstlen + i] = '\0';
	}
	if (size >= dstlen)
		return (dstlen + srclen);
	return (srclen + size);
}
