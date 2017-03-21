/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:25:36 by vpetit            #+#    #+#             */
/*   Updated: 2017/03/21 17:05:24 by vpetit           ###   ########.fr       */
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

static int	ft_display_file(char *argv, int end)
{
	// int		open_fd;
	// int		ret;
	// char	*line;
	//
	// ret = 1;
	// line = NULL;
	// open_fd = open(argv, O_RDONLY);
	// if (open_fd == -1)
	// {
	// 	ft_putstr_fd("open file () failed \n", 2);
	// 	return (-1);
	// }
	// if (end)
	// 	ft_putstr("=====SecondTry : =====\n");
	// while (ret == 1)
	// {


	char	*line_fd0;
	int		p_fd0[2];
	int		fd0 = 0;
	int		out_fd0 = dup(fd0);

	char	*line_fd1;
	int		p_fd1[2];
	int		fd1 = 1;
	int		out_fd1 = dup(fd1);

	char	*line_fd2;
	int		p_fd2[2];
	int		fd2 = 2;
	int		out_fd2 = dup(fd2);

	char	*line_fd3;
	int		p_fd3[2];
	int		fd3 = 3;
	int		out_fd3 = dup(fd3);

	pipe(p_fd0);
	dup2(p_fd0[1], fd0);
	write(fd0, "aaa\nbbb\n", 8);
	dup2(out_fd0, fd0);
	close(p_fd0[1]);

	pipe(p_fd1);
	dup2(p_fd1[1], fd1);
	write(fd1, "111\n222\n", 8);
	dup2(out_fd1, fd1);
	close(p_fd1[1]);

	pipe(p_fd2);
	dup2(p_fd2[1], fd2);
	write(fd2, "www\nzzz\n", 8);
	dup2(out_fd2, fd2);
	close(p_fd2[1]);

	pipe(p_fd3);
	dup2(p_fd3[1], fd3);
	write(fd3, "888\n999\n", 8);
	dup2(out_fd3, fd3);
	close(p_fd3[1]);

	get_next_line(p_fd0[0], &line_fd0);
	if (strcmp(line_fd0, "aaa") != 0)
		ft_putstr("value not good\n");
	get_next_line(p_fd1[0], &line_fd1);
	if (strcmp(line_fd1, "111") != 0)
		ft_putstr("value not good\n");
	get_next_line(p_fd2[0], &line_fd2);
	if (strcmp(line_fd2, "www") != 0)
		ft_putstr("value not good\n");
	get_next_line(p_fd3[0], &line_fd3);
	if (strcmp(line_fd3, "888") != 0)
		ft_putstr("value not good\n");
	get_next_line(p_fd0[0], &line_fd0);
	if (strcmp(line_fd0, "bbb") != 0)
		ft_putstr("value not good\n");
	get_next_line(p_fd1[0], &line_fd1);
	if (strcmp(line_fd1, "222") != 0)
		ft_putstr("value not good\n");
	get_next_line(p_fd2[0], &line_fd2);
	if (strcmp(line_fd2, "zzz") != 0)
		ft_putstr("value not good\n");
	get_next_line(p_fd3[0], &line_fd3);
	if (strcmp(line_fd3, "999") != 0)
		ft_putstr("value not good\n");




		// ret = get_next_line(open_fd, &line);
		// ft_putstr(line);
		// ft_putstr("\n");
	// }
	// if (close(open_fd) == -1)
	// {
	// 	ft_putstr_fd("close file () failed \n", 2);
	// 	return (-1);
	// }
	if (end < 0)
		return (ft_display_file(argv, end + 1));
	return (0);
}

// int			main(int argc, char **argv)
// {
// 	if (argc < 2)
// 	{
// 		ft_putstr_fd("File name missing.\n", 2);
// 		return (-1);
// 	}
// 	else if (argc == 2)
// 		return (ft_display_file(argv[1], 0));
// 	ft_putstr_fd("Too many arguments.\n", 2);
// 	return (-1);
// }

int			main(int argc, char **argv)
{
	if (1 == 2 && argc == 1)
		ft_display_file(argv[1], 0);
	// filename = "/Users/vpetit/prog/git/utils/42/42FileChecker/srcs/gnl/gnl1_2.txt";
	return (0);
}
