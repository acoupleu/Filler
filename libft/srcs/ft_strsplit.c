/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 18:10:41 by acoupleu          #+#    #+#             */
/*   Updated: 2016/03/25 03:35:50 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_len(const char *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**tab_split;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!(tab_split = (char **)malloc(sizeof(char *) * ft_cnt_word(s, c) + 1)))
		return (NULL);
	while (s[i] != '\0' && j < ft_cnt_word(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		k = 0;
		tab_split[j] = (char *)malloc(ft_word_len(&s[i], c) + 1);
		while (s[i] != c && s[i] != '\0')
			tab_split[j][k++] = s[i++];
		tab_split[j][k] = '\0';
		j++;
	}
	tab_split[j] = NULL;
	return (tab_split);
}
