/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 11:50:10 by rdavila           #+#    #+#             */
/*   Updated: 2017/02/21 16:28:55 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_fig(char **figures)
{
	int i;
	int j;

	i = 0;
	while (figures[i])
	{
		j = 0;
		while (figures[i][j])
		{
			ft_putchar(figures[i][j]);
			j++;
		}
		ft_putstr("\n\n");
		i++;
	}
}

void	print_grid(char **grid)
{
	int i;
	int j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			ft_putchar(grid[i][j]);
			j++;
		}
		ft_putstr("\n");
		i++;
	}
}

void	print_order(int *arr, int len)
{
	int i;

	i = 0;
	ft_putstr("[");
	while (i <= len)
	{
		ft_putstr(" ");
		ft_putnbr(arr[i]);
		ft_putstr(" ");
		i++;
	}
	ft_putstr("]\n");
}
