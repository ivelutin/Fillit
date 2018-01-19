/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 15:50:22 by rdavila           #+#    #+#             */
/*   Updated: 2017/02/21 16:30:56 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Remove a tetrimino on the grid.
*/

int		rm_figure(char *figure, char **grid, int row, int column)
{
	t_point	*point;
	int		**coordinates;

	coordinates = gen_coor_array();
	point = (t_point *)malloc(sizeof(*point));
	if (!point)
		return (0);
	point->grid = ft_memalloc(2);
	point->figa = ft_memalloc(2);
	point->figb = ft_memalloc(2);
	point->add = ft_memalloc(2);
	point->grid[0] = row;
	point->grid[1] = column;
	get_coordinates(figure, point, coordinates);
	fill_grid(grid, coordinates, '.');
	free_point(point);
	free(coordinates);
	return (1);
}

/*
** Put a tetrimino on the grid.
*/

int		put_figure(char *figure, char **grid, int *xy, int len)
{
	t_point	*point;
	int		**coordinates;
	char	c;

	c = get_char(figure);
	coordinates = gen_coor_array();
	point = (t_point *)malloc(sizeof(*point));
	if (!point)
		return (0);
	point->grid = ft_memalloc(2);
	point->figa = ft_memalloc(2);
	point->figb = ft_memalloc(2);
	point->add = ft_memalloc(2);
	point->grid[0] = xy[0];
	point->grid[1] = xy[1];
	get_coordinates(figure, point, coordinates);
	if (!coor_validator(grid, coordinates, len))
		return (0);
	fill_grid(grid, coordinates, c);
	free_point(point);
	free(coordinates);
	return (1);
}

/*
** Try to fit every tetrimino inside the grid
*/

int		fillit(char **grid, char **figures, int len, int k)
{
	int		i;
	int		j;

	if (!figures[k])
		return (1);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (put_figure(figures[k], grid, make_array(i, j), len))
			{
				if (fillit(grid, figures, len, k + 1))
					return (1);
				else
					rm_figure(figures[k], grid, i, j);
			}
			j++;
		}
		i++;
	}
	return (0);
}

/*
** Try to find the solution with the minimum square.
** If no solution is found, try next square size.
*/

void	solver(char **figures, int num)
{
	char	**grid;
	int		len;

	len = ft_sqrt(num * 4);
	grid = generate_grid(len);
	while (!fillit(grid, figures, len, 0))
	{
		len++;
		free_grid(grid);
		grid = generate_grid(len);
	}
	print_grid(grid);
	free_grid(grid);
}
