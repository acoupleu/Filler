/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 17:28:38 by acoupleu          #+#    #+#             */
/*   Updated: 2016/09/27 17:07:50 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	go_top_r(t_fenv fenv)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	count = 0;
	while (y < fenv.tab_h)
	{
		x = fenv.tab_w - 1;
		while (x >= 0)
		{
			if (is_placeable(fenv, y, x))
			{
				ft_printf("%d %d\n", y, x);
				filler(&fenv);
			}
			x--;
			count++;
		}
		y++;
		if (count == (fenv.tab_h * fenv.tab_w))
			ft_printf("0 0\n");
	}
}

void	go_top_l(t_fenv fenv)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	count = 0;
	while (y < fenv.tab_h)
	{
		x = 0;
		while (x < fenv.tab_w)
		{
			if (is_placeable(fenv, y, x))
			{
				ft_printf("%d %d\n", y, x);
				filler(&fenv);
			}
			x++;
			count++;
		}
		y++;
		if (count == (fenv.tab_h * fenv.tab_w))
			ft_printf("0 0\n");
	}
}

void	go_bot_r(t_fenv fenv)
{
	int	y;
	int	x;
	int	count;

	y = fenv.tab_h - 1;
	count = 0;
	while (y >= 0)
	{
		x = fenv.tab_w - 1;
		while (x >= 0)
		{
			if (is_placeable(fenv, y, x))
			{
				ft_printf("%d %d\n", y, x);
				filler(&fenv);
			}
			x--;
			count++;
		}
		y--;
		if (count == (fenv.tab_h * fenv.tab_w))
			ft_printf("0 0\n");
	}
}

void	go_bot_l(t_fenv fenv)
{
	int	y;
	int	x;
	int	count;

	y = fenv.tab_h - 1;
	count = 0;
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
			x++;
			count++;
		}
		y--;
		if (count == (fenv.tab_h * fenv.tab_w))
			ft_printf("0 0\n");
	}
}

void	fill_mid_r(t_fenv fenv)
{
	int	y;
	int	x;

	y = fenv.tab_h / 2;
	while (y >= 0)
	{
		x = fenv.tab_w - 1;
		while (x >= 0)
		{
			if (is_placeable(fenv, y, x))
			{
				ft_printf("%d %d\n", y, x);
				filler(&fenv);
			}
			else
				x--;
		}
		y--;
		if (y == 0 && x == 0)
			go_top_r(fenv);
	}
}
