/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 17:46:44 by acoupleu          #+#    #+#             */
/*   Updated: 2016/09/27 17:27:44 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 100000

# include "libft.h"
# include <fcntl.h>

# define ENDL '\n'

typedef struct	s_struct
{
	int		nd;
	char	*res;
}				t_struct;

int				get_next_line(int const fd, char **line);

#endif
