/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 15:53:49 by acoupleu          #+#    #+#             */
/*   Updated: 2016/09/27 18:06:37 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	is_intab(t_fenv fenv, int x, int y)
{
	if (x + fenv.piece_w > fenv.tab_w)
		return (0);
	else if (y + fenv.piece_h > fenv.tab_h)
		return (0);
	else
		return (1);
}

int	is_placeable(t_fenv fenv, int y, int x)
{
	int	xt;
	int	yt;
	int	count;

	if (!is_intab(fenv, x, y))
		return (0);
	yt = 0;
	count = 0;
	while (yt + y < fenv.tab_h && yt < fenv.piece_h)
	{
		xt = 0;
		while (xt + x < fenv.tab_w && xt < fenv.piece_w)
		{
			if (fenv.tab[y + yt][x + xt] != '.' && fenv.piece[yt][xt] == '*')
				count++;
			if (fenv.tab[y + yt][x + xt] != fenv.player &&
				fenv.piece[yt][xt] == '*' && fenv.tab[y + yt][x + xt] != '.')
				return (0);
			xt++;
		}
		yt++;
	}
	return (count != 1 ? 0 : 1);
}

int	is_top(t_fenv fenv)
{
	if (ft_strchr(fenv.tab[0], fenv.player) != NULL)
		return (1);
	return (0);
}

int	is_top_from_bot(t_fenv fenv)
{
	int i;
	int	j;

	i = 0;
	j = fenv.tab_w * 1 / 10;
	while (j + i < fenv.tab_w)
	{
		if (fenv.tab[0][j + i] == 'O'
		|| ft_strchr(fenv.tab[fenv.tab_h * 2 / 10], 'O') != NULL)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	is_bot(t_fenv fenv)
{
	if (ft_strchr(fenv.tab[fenv.tab_h - 1], fenv.player) != NULL)
		return (1);
	return (0);
}
