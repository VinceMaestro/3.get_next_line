/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:25:36 by vpetit            #+#    #+#             */
/*   Updated: 2017/03/07 01:41:37 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

static int	ft_display_file(char *argv)
{
	int		open_fd;
	char	**line;

	open_fd = open(argv, O_RDWR);
	if (open_fd == -1)
	{
		ft_putstr_fd("open file () failed \n", 2);
		return (-1);
	}
	line = (char**)malloc(sizeof(char*));
	if (line)
	{
		while (get_next_line(open_fd, line) == 1)
		{
			// ft_putstr("Line :\n");
			ft_putstr(*line);
			ft_putstr("\n");
		}
	}
	if (close(open_fd) == -1)
	{
		ft_putstr_fd("close file () failed \n", 2);
		return (-1);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putstr_fd("File name missing.\n", 2);
		return (-1);
	}
	else if (argc == 2)
		return (ft_display_file(argv[1]));
	ft_putstr_fd("Too many arguments.\n", 2);
	return (-1);
}
