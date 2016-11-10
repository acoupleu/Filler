/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 21:04:19 by acoupleu          #+#    #+#             */
/*   Updated: 2016/03/23 15:52:31 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ch;

	i = 0;
	ch = (unsigned char*)s;
	while (i < n)
	{
		ch[i] = (unsigned char)c;
		i++;
	}
	return (ch);
}
