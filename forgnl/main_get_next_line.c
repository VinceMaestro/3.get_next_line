/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:25:36 by vpetit            #+#    #+#             */
/*   Updated: 2017/03/22 23:37:42 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>

// FOR 2 fd
// static int	ft_display_file(char *argv1, char *argv2, char *argv3)
// {
// 	int		open_fd1;
// 	int		open_fd2;
// 	int		open_fd3;
// 	int		ret1;
// 	int		ret2;
// 	int		ret3;
// 	char	*line1;
// 	char	*line2;
// 	char	*line3;
// 	// int		cpt;
//
// 	// cpt = 0;
// 	ret1 = 1;
// 	ret2 = 1;
// 	ret3 = 1;
// 	line1 = NULL;
// 	line2 = NULL;
// 	line3 = NULL;
// 	open_fd1 = open(argv1, O_RDWR);
// 	open_fd2 = open(argv2, O_RDWR);
// 	open_fd3 = open(argv3, O_RDWR);
// 	if (open_fd1 == -1 || open_fd2 == -1 || open_fd3 == -1)
// 	{
// 		ft_putstr_fd("open file () failed \n", 2);
// 		return (-1);
// 	}
// 	while (ret1 == 1 || ret2 == 1 || ret3 == 1)
// 	{
// 		ret1 = get_next_line(open_fd1, &line1);
// 		ft_putstr(line1);
// 		if (ret1)
// 			ft_putstr("\n");
// 		// cpt++;
// 		ret2 = get_next_line(open_fd2, &line2);
// 		ft_putstr(line2);
// 		if (ret2)
// 			ft_putstr("\n");
//
// 		ret3 = get_next_line(open_fd3, &line3);
// 		ft_putstr(line3);
// 		if (ret3)
// 			ft_putstr("\n");
// 	}
// 	if (close(open_fd1) == -1 || close(open_fd2) == -1 || close(open_fd3) == -1)
// 	{
// 		ft_putstr_fd("close file () failed \n", 2);
// 		return (-1);
// 	}
// 	return (0);
// }
//
// int			main(int argc, char **argv)
// {
// 	if (argc != 4)
// 	{
// 		ft_putstr_fd("usage: ./gnl file1 file2 file3\n", 2);
// 		return (-1);
// 	}
// 	else
// 		return (ft_display_file(argv[1], argv[2], argv[3]));
// }


static int	ft_display_file(char *argv)
{
	int		open_fd;
	int		ret;
	char	*line;
	int		cpt = 0;

	ret = 1;
	line = NULL;
	open_fd = open(argv, O_RDONLY);
	if (open_fd == -1)
	{
		ft_putstr_fd("open file () failed \n", 2);
		return (-1);
	}
	while (ret == 1)
	{
		ret = get_next_line(open_fd, &line);
		if (ret)
			cpt++;
		ft_putstr(line);
		ft_putnbr(ret);
		if (ret)
			ft_putstr("\n");
	}
	// ft_putnbr(cpt);
	if (close(open_fd) == -1)
	{
		ft_putstr_fd("close file () failed \n", 2);
		return (-1);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putstr_fd("File name missing.\n", 2);
		return (-1);
	}
	else if (argc == 2)
		return (ft_display_file(argv[1]));
	ft_putstr_fd("Too many arguments.\n", 2);
	return (-1);
}
