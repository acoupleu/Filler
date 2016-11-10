/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cnt_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 01:01:24 by acoupleu          #+#    #+#             */
/*   Updated: 2016/03/31 20:31:06 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_cnt_word(const char *s1, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s1[i])
	{
		while (s1[i] && s1[i] == c)
			i++;
		if (s1[i] != c && s1[i] != '\0')
		{
			count++;
			while (s1[i] && s1[i] != c)
				i++;
		}
	}
	return (count);
}
