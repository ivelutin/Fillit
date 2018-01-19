/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 11:49:23 by rdavila           #+#    #+#             */
/*   Updated: 2017/02/21 16:25:39 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Replace the characters in the coordinates 'coor' for 'c'
*/

void	fill_grid(char **grid, int **coor, char c)
{
	int i;

	i = 0;
	while (i < 4)
	{
		grid[coor[i][0]][coor[i][1]] = c;
		i++;
	}
}

/*
** Get the respective letter of the tetrimino ('A', 'B', 'C', ...)
*/

char	get_char(char *fig)
{
	char c;

	c = '.';
	while (*fig)
	{
		if (*fig != '.' && *fig != '\n')
		{
			c = *fig;
			break ;
		}
		fig++;
	}
	return (c);
}

/*
** Free the grid
*/

void	free_grid(char **grid)
{
	int i;

	i = 0;
	while (grid[i])
	{
		free(grid[i]);
		grid[i] = NULL;
		i++;
	}
	free(grid);
	grid = NULL;
}

/*
** Free a struct t_point
*/

void	free_point(t_point *p)
{
	free(p->grid);
	p->grid = NULL;
	free(p->figa);
	p->figa = NULL;
	p->figb = NULL;
	free(p->add);
	p->add = NULL;
	free(p);
	p = NULL;
}

/*
** Change the readout from '#' to respective letter
*/

void	change_readout(char *readout)
{
	char	c;
	int		i;
	int		count;

	c = 'A';
	i = 0;
	count = 0;
	while (readout[i])
	{
		if (readout[i] == '#')
		{
			count++;
			readout[i] = c;
		}
		if (count == 4)
		{
			c++;
			count = 0;
		}
		i++;
	}
}
