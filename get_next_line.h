/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 07:16:16 by vpetit            #+#    #+#             */
/*   Updated: 2017/02/23 18:14:27 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_get_next_line_list	t_gnl_list;
typedef struct s_struct_gnl			t_gnl;

struct	s_get_next_line_list
{
	void		*content;
	int			content_size;
	int			fd;
	t_gnl_list	*next_fd;
	t_gnl_list	*first_fd;

};

struct	s_struct_gnl
{
	char				*str;
	char				*end;
	int					reader;
	t_gnl_list			*ptr_lst;
	int					*len_str;
};

# ifndef BUFF_SIZE
#  define BUFF_SIZE 30
# endif

int		get_next_line(const int fd, char **line);

#endif
