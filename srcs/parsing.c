/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 19:48:33 by acoupleu          #+#    #+#             */
/*   Updated: 2016/09/27 17:09:59 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	parse_player(t_fenv *fenv, char *player_info)
{
	int	i;
	int	p_nbr;

	i = 0;
	while (player_info[i] && !(ft_isdigit(player_info[i])))
		i++;
	p_nbr = player_info[i] - 48;
	if (p_nbr == 1)
		fenv->player = 'O';
	else
		fenv->player = 'X';
}

void	parse_tab_size(t_fenv *fenv, char *tab_info)
{
	char	**tab_split;

	tab_split = ft_strsplit(tab_info, ' ');
	fenv->tab_h = ft_atoi(tab_split[1]);
	fenv->tab_w = ft_atoi(tab_split[2]);
	if (fenv->tab_h > 20 || fenv->tab_w > 20)
		fenv->map = 1;
	else
		fenv->map = 0;
}

void	parse_tab(t_fenv *fenv, char *first_line)
{
	int		i;

	fenv->tab[0] = ft_strsub(first_line, 4, fenv->tab_w);
	i = 1;
	while (i < fenv->tab_h)
	{
		get_next_line(0, &first_line);
		fenv->tab[i] = ft_strsub(first_line, 4, fenv->tab_w);
		i++;
	}
}

void	parse_piece_size(t_fenv *fenv, char *piece_info)
{
	char	**piece_split;
	int		i;

	i = 0;
	piece_split = ft_strsplit(piece_info, ' ');
	fenv->piece_h = ft_atoi(piece_split[1]);
	fenv->piece_w = ft_atoi(piece_split[2]);
}

void	parse_piece(t_fenv *fenv, char *first_line)
{
	int	i;

	i = 0;
	parse_piece_size(fenv, first_line);
	fenv->piece = (char **)malloc(sizeof(char *) * (fenv->piece_h + 1));
	while (i < fenv->piece_h)
	{
		get_next_line(0, &first_line);
		fenv->piece[i] = ft_strdup(first_line);
		i++;
	}
	fenv->piece[fenv->piece_h] = NULL;
	fenv->end = 1;
}
