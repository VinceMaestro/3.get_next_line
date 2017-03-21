/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:25:36 by vpetit            #+#    #+#             */
/*   Updated: 2017/03/21 21:43:27 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>

// FOR 2 fd
// static int	ft_display_file(char *argv1, char *argv2, int end)
// {
// 	int		open_fd1;
// 	int		open_fd2;
// 	int		ret;
// 	int		ret2;
// 	char	*line;
// 	int		cpt;
//
// 	cpt = 0;
// 	ret = 1;
// 	ret2 = 1;
// 	line = NULL;
// 	open_fd1 = open(argv1, O_RDWR);
// 	open_fd2 = open(argv2, O_RDWR);
// 	if (open_fd1 == -1 || open_fd2 == -1)
// 	{
// 		ft_putstr_fd("open file () failed \n", 2);
// 		return (-1);
// 	}
// 	if (end)
// 		ft_putstr("=====SecondTry : =====\n");
// 	while (ret == 1)
// 	{
// 		ret = get_next_line(open_fd1, &line);
// 		ft_putstr(line);
// 		ft_putstr("\n");
// 		cpt++;
// 		ret2 = get_next_line(open_fd2, line);
// 		ft_putstr(*line);
// 		ft_putstr("\n");
// 	}
// 	if (close(open_fd1) == -1 || close(open_fd2) == -1)
// 	{
// 		ft_putstr_fd("close file () failed \n", 2);
// 		return (-1);
// 	}
// 	if (end < 0)
// 		return (ft_display_file(argv1, argv2, end + 1));
// 	return (0);
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
		// ft_putnbr(ret);
		if (ret)
			ft_putstr("\n");
	}
	ft_putnbr(cpt);
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
