/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 20:16:20 by acoupleu          #+#    #+#             */
/*   Updated: 2016/06/01 20:21:47 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc_int(size_t size)
{
	int	*mem;

	mem = (int *)malloc(sizeof(int) * size);
	if (mem == NULL)
		return (NULL);
	ft_memset_int(mem, 0, size);
	return (mem);
}
