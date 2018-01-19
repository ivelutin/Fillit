/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:49:27 by rdavila           #+#    #+#             */
/*   Updated: 2017/02/15 15:11:19 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Get coordinates (x, y) based on a string spot.
*/

int		*find_coor(int spot, int row_length)
{
	int *coordinates;

	coordinates = (int *)malloc(sizeof(*coordinates) * 3);
	if (!coordinates)
		return (NULL);
	coordinates[0] = spot / row_length;
	coordinates[1] = spot % row_length;
	return (coordinates);
}

/*
** Add 2 given coordinates.
*/

int		*sum_coor(int *first, int *second)
{
	int *ret;

	ret = (int *)malloc(sizeof(*ret) * 2);
	if (!ret)
		return (NULL);
	ret[0] = first[0] + second[0];
	ret[1] = first[1] + second[1];
	return (ret);
}

/*
** Substract 2 given coordinates.
*/

int		*rest_coor(int *first, int *second)
{
	int *ret;

	ret = (int *)malloc(sizeof(*ret) * 2);
	if (!ret)
		return (NULL);
	ret[0] = first[0] - second[0];
	ret[1] = first[1] - second[1];
	return (ret);
}

/*
** Get the coordinates a tetrimino would occupy in the grid based on a given
** point (p->grid[x], p->grid[y]) in the grid.
*/

void	get_coordinates(char *figure, t_point *p, int **coordinates)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (figure[i] && count < 4)
	{
		if (figure[i] >= 'A' && figure[i] <= 'Z')
		{
			p->figa = find_coor(i, 5);
			p->next = i + ft_tochar(figure + i + 1, figure[i]);
			if (!count)
			{
				p->next = i;
				i--;
			}
			p->figb = find_coor(p->next, 5);
			p->add = rest_coor(p->figb, p->figa);
			p->grid = sum_coor(p->grid, p->add);
			coordinates[count] = p->grid;
			p->figa = p->figb;
			count++;
		}
		i++;
	}
}

/*
** Check if the coordinates given are available. Basically
** check that the coordinates are within the grid and that the
** respective spots are a dot ('.').
*/

int		coor_validator(char **grid, int **coor, int len)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (coor[i][0] < 0 || coor[i][1] < 0)
			return (0);
		if (coor[i][0] >= len || coor[i][1] >= len)
			return (0);
		if (grid[coor[i][0]][coor[i][1]] != '.')
			return (0);
		i++;
	}
	return (1);
}
