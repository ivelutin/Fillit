/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 14:50:18 by rdavila           #+#    #+#             */
/*   Updated: 2017/02/21 16:18:36 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Generate an empty grid of (len * len)
*/

char	**generate_grid(int len)
{
	char	**grid;
	int		i;
	int		j;

	i = 0;
	grid = (char **)malloc(sizeof(char *) * len + 1);
	while (i < len)
	{
		j = 0;
		grid[i] = (char *)malloc(sizeof(char) * len + 1);
		while (j < len)
		{
			grid[i][j] = '.';
			j++;
		}
		grid[i][j] = '\0';
		i++;
	}
	grid[i] = NULL;
	return (grid);
}

/*
** Generate a 2 * 4 bidimentional array to save 4 coordinates (x, y)
*/

int		**gen_coor_array(void)
{
	int	**coordinates;
	int a;
	int	b;

	a = 0;
	coordinates = (int **)malloc(sizeof(*coordinates) * 4);
	while (a < 4)
	{
		coordinates[a] = (int *)malloc(sizeof(**coordinates) * 2);
		a++;
	}
	a = 0;
	while (a < 4)
	{
		b = 0;
		while (b < 2)
		{
			coordinates[a][b] = 0;
			b++;
		}
		a++;
	}
	return (coordinates);
}

/*
** Generate an array of length 'n' with values 0, 1, ..., n
*/

int		*generate_array(int n)
{
	int i;
	int	*ret;

	i = 0;
	ret = (int *)malloc(sizeof(*ret) * n);
	if (!ret)
		return (NULL);
	while (i < n)
	{
		ret[i] = i;
		i++;
	}
	return (ret);
}

/*
** Make a simple array. Made this function to fix a norme error
*/

int		*make_array(int x, int y)
{
	int *ret;

	ret = (int *)malloc(sizeof(*ret) * 2);
	ret[0] = x;
	ret[1] = y;
	return (ret);
}

/*
** Get the square root of a number
*/

int		ft_sqrt(int nb)
{
	int	root;

	root = 0;
	if (nb < 0)
	{
		return (0);
	}
	while ((root * root) < nb)
	{
		root += 1;
	}
	return (root);
}
