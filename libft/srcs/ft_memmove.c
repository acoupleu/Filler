/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 22:23:52 by acoupleu          #+#    #+#             */
/*   Updated: 2016/03/23 18:38:06 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *)malloc(sizeof(char) * n);
	ft_memcpy(temp, src, n);
	ft_memcpy(dest, temp, n);
	free(temp);
	return (dest);
}
