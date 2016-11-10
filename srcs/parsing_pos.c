/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 17:39:47 by acoupleu          #+#    #+#             */
/*   Updated: 2016/09/27 17:57:58 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		am_i_top(t_fenv *fenv)
{
	int	i;
	int	j;

	i = 0;
	fenv->first = 1;
	while (i < fenv->tab_h)
	{
		j = 0;
		while (j < fenv->tab_w)
		{
			if (fenv->tab[i][j] != '.' && fenv->tab[i][j] == fenv->player)
				return (1);
			else if (fenv->tab[i][j] != '.' && fenv->tab[i][j] != fenv->player)
				return (2);
			j++;
		}
		i++;
	}
	return (0);
}

int		is_mid(t_fenv fenv)
{
	if (fenv.tab[fenv.tab_h / 2][0] == fenv.player
		|| fenv.tab[fenv.tab_h / 2][fenv.tab_w - 1] == fenv.player)
		return (1);
	else
		return (0);
}

void	fill_mid_l(t_fenv fenv)
{
	int	y;
	int	x;

	y = fenv.tab_h / 2;
	while (y >= 0)
	{
		x = 0;
		while (x < fenv.tab_w)
		{
			if (is_placeable(fenv, y, x))
			{
				ft_printf("%d %d\n", y, x);
				filler(&fenv);
			}
			else
				x++;
		}
		y--;
	}
	go_bot_r(fenv);
}
