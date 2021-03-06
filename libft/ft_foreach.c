/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 18:03:35 by vpetit            #+#    #+#             */
/*   Updated: 2017/01/03 17:02:16 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int lenght, void (*f)(int))
{
	int		cpt;

	cpt = 0;
	while (cpt < lenght)
	{
		f(tab[cpt]);
		cpt += 1;
	}
}
