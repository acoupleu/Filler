/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 13:24:21 by acoupleu          #+#    #+#             */
/*   Updated: 2016/09/27 18:10:35 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	do_algo2(t_fenv *fenv)
{
	if (!is_top(*fenv))
		go_top_l(*fenv);
	else if (!is_bot(*fenv))
		go_bot_l(*fenv);
	else if (!is_mid(*fenv))
		fill_mid_l(*fenv);
	else
		go_top_l(*fenv);
}

void	do_algo(t_fenv *fenv)
{
	if (fenv->top == 1 && fenv->map != 0)
	{
		if (!is_bot(*fenv))
			go_bot_r(*fenv);
		else if (!is_top(*fenv))
			go_top_r(*fenv);
		else if (!is_mid(*fenv))
			fill_mid_r(*fenv);
		else
			go_top_r(*fenv);
	}
	else if (fenv->top == 1 && fenv->map == 0)
	{
		if (!is_top(*fenv))
			go_top_r(*fenv);
		else if (!is_bot(*fenv))
			go_bot_r(*fenv);
		else
			go_top_r(*fenv);
	}
	else
		do_algo2(fenv);
}

void	filler(t_fenv *fenv)
{
	char	*line;

	fenv->end = 0;
	while (get_next_line(0, &line))
	{
		if (line[0] == '0' && line[1] == '0' && line[2] == '0')
			parse_tab(fenv, line);
		if (line[0] == 'P' && line[1] == 'i')
			parse_piece(fenv, line);
		if (fenv->end == 1)
			break ;
	}
	if (fenv->first == 0)
		fenv->top = am_i_top(fenv);
	do_algo(fenv);
}

int		main(void)
{
	t_fenv	fenv;
	char	*line;

	fenv.first = 0;
	get_next_line(0, &line);
	if (line[0] == '$')
		parse_player(&fenv, line);
	get_next_line(0, &line);
	if (line[0] == 'P' && line[1] == 'l')
		parse_tab_size(&fenv, line);
	fenv.tab = (char **)malloc(sizeof(char *) * (fenv.tab_h + 1));
	fenv.tab[fenv.tab_h] = NULL;
	filler(&fenv);
	return (0);
}
