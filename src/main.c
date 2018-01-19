/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 16:27:21 by rdavila           #+#    #+#             */
/*   Updated: 2017/02/21 15:46:22 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	char	**tetriminos;
	char	*readout;
	int		num;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	if (!(readout = get_input(av[1])))
	{
		ft_putstr("error\n");
		return (0);
	}
	num = count_tetriminos(readout, 0, 1, 0);
	tetriminos = split_tetriminos(readout);
	if (!num || !tetriminos)
	{
		ft_putstr("error\n");
		return (0);
	}
	solver(tetriminos, num);
	return (0);
}
