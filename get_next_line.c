/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 07:16:02 by vpetit            #+#    #+#             */
/*   Updated: 2017/03/02 18:29:47 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
// int	get_next_line(const int fd, char **line)
// {
// 	char			*endl;
// 	char			*text;
// 	static t_list	*reader;
//
// 	endl = NULL;
// 	((!reader) ? (reader = (t_list*)ft_memalloc(t_list)));
// 	((reader) ? (*reader = (t_list){(char*)ft_memalloc(BUFF_SIZE)), BUFF_SIZE, NULL});
// 	if (!fd || !line || !BUFF_SIZE || !reader || !reader->cont)
// 		return (-1);
// 	while (!(reader->cont_sze = ft_max((size_t)(ft_memchr(buff, '\n', BUFF_SIZE) - reader->cont), 0)))
// 	{
// 		read(fd, buff, BUFF_SIZE));
// 		reader->cont = ft_strjoin(reader->cont, (buff, )[0]  ft_memchr(buff, '\n', BUFF_SIZE)))
// 	}
// }
//
static void	*ft_memincr(void *src, int new_size)
{
	void	*buff;

	printf("memincr ATTEMPT\n");
	buff = (void*)malloc(sizeof(void) * (new_size + 1));
	if (buff)
	{
		ft_bzero(buff, new_size + 1);
		if (src)
		{
			printf("src is : %s\n", src);
			ft_memcpy(buff, src, new_size);
			printf("memincr SUCCESS buff is : %s\n", buff);
			//ft_memdel(&src);
			// printf("memdel SUCCESS\n");
		}
	}
	return (buff);
}

// static void	*ft_lstfd(t_gnl_list *fd_lst, int fd)
// {
// 	t_gnl_list	*new;
// 	t_gnl_list	*ptr;
//
// 	// (!(fd_lst) ? (fd_lst = (t_gnl_list*)malloc(sizeof(t_gnl_list))) : fd_lst);
// 	((fd_lst) ? (ptr = fd_lst) :\
// 		(ptr = NULL));
// 	if (fd_lst)
// 	{
//  		printf("ptr define next s Trying to print : %i : fd_lst : %i\n", ptr->fd, fd_lst->fd);
// 		// printf("ptr define next s : %p\n", ptr->next);
// 		while (ptr->next && ptr->fd != fd)
// 		{
// 			printf("just one?\n");
// 			ptr = ptr->next;
// 			printf("sucess one\n");
// 		}
// 		printf("exiting while\n");
// 		if (ptr->fd == fd)
// 			return (ptr);
// 	}
// 	printf("malloc new\n");
// 	new = (t_gnl_list*)malloc(sizeof(t_gnl_list));
// 	if (new)
// 	{
// 		printf("success malloc\n");
// 		new->fd = fd;
// 		new->cont = NULL;
// 		new->cont_sze = 0;
// 		new->next = NULL;
// 		((ptr) ? (ptr->next = new) :\
// 			(ptr = new));
// 		printf("exit ft_lstfd\n");
// 	}
// 	return ((ptr->next) ? (ptr = ptr->next) : (ptr));
// }
//
// static void	ft_init_gnl(t_gnl_list *fd_lst, int fd, t_gnl *s)
// {
// 	printf("1\n");
// 	s->reader = BUFF_SIZE;
// 	printf("2\n");
// 	s->ptr_lst = ft_lstfd(fd_lst, fd);
// 	printf("3\n");
// 	s->str = s->ptr_lst->cont;
// 	printf("4\n");
// 	s->len_str = &(s->ptr_lst->cont_sze);
// 	printf("5\n");
// 	s->end = ft_memchr(s->str, '\n', *(s->len_str));
// 	printf("6 : %p\n", s->end);
// }
//
// int			get_next_line(const int fd, char **line)
// {
// 	static t_gnl_list	*fd_lst;
// 	t_gnl				s;
//
// 	if (!fd_lst)
// 		fd_lst = (t_gnl_list*)malloc(sizeof(t_gnl_list));
// 	ft_putstr("INIT : START\n");
// 	if (!fd || !line || BUFF_SIZE < 1 || !fd_lst)
// 		return (-1);
// 	ft_init_gnl(fd_lst, fd, &s);
// 	ft_putstr("INIT : SUCCESS\n");
// 	if (fd_lst && s.ptr_lst)
// 	{
// 		while (s.reader == BUFF_SIZE && !s.end)
// 		{
// 			printf("ENTERING LOOP\n");
// 			*(s.len_str) += BUFF_SIZE;
// 			printf("len_str : %i\n", *(s.len_str));
// 			s.str = ft_memincr(s.str, *(s.len_str));
// 			printf("str : %s\n", s.str);
// 			if (!s.str)
// 				return (-1);
// 			s.reader = read(fd, &s.str[*(s.len_str) - BUFF_SIZE], BUFF_SIZE);
// 			s.end = ft_memchr(s.str, '\n', *(s.len_str));
// 			printf("str : %p\n", s.str);
// 			printf("end : %p\n", s.end);
// 			printf("EXITING LOOP\n");
// 		}
// 		printf("NEXT\n");
// 		if (s.end)
// 		{
// 			printf("FOUND ret chariot\n");
// 			printf("FINAL str %s\n", s.str);
// 			printf("FINAL SIZE %li\n", s.end - s.str);
// 			*line = ft_memalloc(s.end - s.str);
// 			if (!*line)
// 				return (-1);
// 			*line = ft_memcpy(*line, s.str, s.end - s.str - 1);
// 			line[s.end - s.str - 1] = 0;
// 			*(s.len_str) = s.reader - (s.end - s.str + 1);
// 			// ft_memdel(&s.str);
// 			s.str = ft_memincr(s.end + 1, *(s.len_str));
// 		}
// 		else
// 		{
// 			*(s.len_str) += s.reader;
// 			*line = ft_memalloc(*(s.len_str) + 1);
// 			*line = s.str;
// 			line[*(s.len_str) + 1] = 0;
// 			s.str = ft_memincr(s.str, *(s.len_str));
// 		}
// 		if (!s.str)
// 			return (-1);
// 	}
// 	else
// 		return (-1);
// 	printf("Assigning line\n");
// 	return ((s.reader <  BUFF_SIZE) ? (0) : (1));
// }
//
// //sanitizer adress

static t_gnl_list	*ft_getlst_fd(t_gnl_list *fd_lst, int fd)
{
	if (fd_lst)
	{
		while (fd_lst->next && fd_lst->fd != fd)
			fd_lst = fd_lst->next;
		if (fd_lst->fd == fd)
			return (fd_lst);
		fd_lst->next = (fd_lst*)malloc(sizeof(fd_lst));
		if (!fd_lst->next)
			return (NULL);
		fd_lst->next->first = fd_lst->first;
		fd_lst = fd_lst->next;
	}
	else
	{
		fd_lst = (fd_lst*)malloc(sizeof(fd_lst));
		if (!fd_lst)
			return (NULL);
		fd_lst->first = fd_lst;
	}
	fd_lst->fd = fd;
	fd_lst->cont = '\0';
	fd_lst->cont_sze = 0;
	return (fd_lst);
}

int					get_next_line(const int fd, char **line)
{
	static t_gnl_list	*fd_lst;
	t_gnl_list			*tmp;
	char				*tmpline;
	int					reader;

	if (!fd || !line || BUFF_SIZE < 1 || !(fd_lst = ft_getlst_fd(fd_lst, fd)))
		return (-1);
	tmpline = fd_lst->cont;
	// If \n found in cont print
	if (fd_lst->cont = (ft_memchr(fd_lst->cont, '\n', fd_lst.cont_sze)))
	{
		// fd_lst = ft_print_from_fd(fd_lst, tmpline);
		// ft_memdel(&tmpline);
		// return (1);

		if (tmpline != fd_lst->cont)
			fd_lst.cont_sze -= (*fd_lst->cont - tmpline);
		*fd_lst->cont = 0;
		ft_putstr(tmpline - (tmpline - fd_lst->cont));
		ft_memdel(&tmpline);
		fd_lst = fd_lst->first;
		return (1);
	}
	else
	{
		// Increase cont_sze, read BUFF_SIZE and write in cont
		fd_lst->cont = ft_memincr(tmpline, fd_lst.cont_sze + BUFF_SIZE);
		ft_memdel(&tmpline);
		while (((reader = read(fd_lst.fd, &(*fd_lst->cont + fd_lst.cont_sze), \
				BUFF_SIZE)) == BUFF_SIZE) && !(fd_lst->cont = \
				ft_memchr(&(*fd_lst->cont + fd_lst.cont_sze), '\n', BUFF_SIZE)))
		{
			// if reader == BUFF_SIZE et pas de \n on Increase content
			fd_lst.cont_sze += BUFF_SIZE;
			tmpline = fd_lst->cont;
			fd_lst->cont = ft_memincr(tmpline, fd_lst.cont_sze + BUFF_SIZE);
			ft_memdel(&tmpline);
		}
		tmpline = fd_lst->cont;
		((fd_lst->cont = ft_memchr(&(*fd_lst->cont + fd_lst.cont_sze), '\n', \
			BUFF_SIZE)) ? (ft_putstr(&(*tmpline - (fd_lst->cont - tmpline))) : \
			() )
	}


}
