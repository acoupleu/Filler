/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 13:43:28 by acoupleu          #+#    #+#             */
/*   Updated: 2016/09/27 17:52:39 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct	s_fenv
{
	int		tab_h;
	int		tab_w;
	int		piece_h;
	int		piece_w;
	int		end;
	int		top;
	int		map;
	int		first;
	char	player;
	char	**tab;
	char	**piece;
}				t_fenv;

/*
** Parsing
*/

void			parse_player(t_fenv *fenv, char *player_info);
void			parse_tab_size(t_fenv *fenv, char *tab_info);
void			parse_tab(t_fenv *fenv, char *first_line);
void			parse_piece_size(t_fenv *fenv, char *piece_info);
void			parse_piece(t_fenv *fenv, char *first_line);

/*
** Check
*/

int				is_placeable(t_fenv fenv, int x, int y);
int				is_intab(t_fenv fenv, int x, int y);
int				is_top(t_fenv fenv);
int				is_bot(t_fenv fenv);
int				is_mid(t_fenv fenv);
int				is_top_from_bot(t_fenv fenv);
int				am_i_top(t_fenv *fenv);

/*
** Moves
*/

void			go_top_r(t_fenv fenv);
void			go_top_l(t_fenv fenv);
void			go_bot_r(t_fenv fenv);
void			go_bot_l(t_fenv fenv);
void			fill_mid_r(t_fenv fenv);
void			fill_mid_l(t_fenv fenv);

void			filler(t_fenv *fenv);

#endif
