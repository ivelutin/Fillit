/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 15:06:30 by rdavila           #+#    #+#             */
/*   Updated: 2017/02/21 16:28:44 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Check for connections between the '#'
*/

int		ft_val(char *s, int ch, int count)
{
	int	i;

	i = -1;
	while (s[++i] != '\0')
	{
		if (s[i] == '#' || s[i] == '\n' || s[i] == '.')
			ch++;
		if (s[i] == '#' && s[i + 1] == '#')
			count++;
		if (s[i] == '#' && s[i - 1] == '#')
			count++;
		if ((ch > 5) && s[i] == '#' && s[i - 5] == '#')
			count++;
		if ((ch < 15) && s[i] == '#' && s[i + 5] == '#')
			count++;
		if (ch == 20)
		{
			if (count != 6 && count != 8)
				return (0);
			count = 0;
			ch = 0;
			i++;
		}
	}
	return (1);
}

/*
** Check for valid characters
*/

int		validation(char *s)
{
	int	i;
	int	ch;
	int	nlines;

	i = -1;
	ch = 0;
	nlines = 0;
	while (s[++i] != '\0')
	{
		ch += ((s[i] == '#') ? 100 : 0);
		ch += ((s[i] == '.') ? 1 : 0);
		nlines += ((s[i] == '\n') ? 1 : 0);
		if (ch == 412 && nlines == 3)
		{
			ch = 0;
			nlines = -2;
		}
		if (s[i] != '\n' && s[i] != '#' && s[i] != '.')
			return (0);
	}
	return ((ch == 0 && nlines == -1) ? 1 : 0);
}

/*
** Count the number of tetriminos that are in the input file.
** This function checks for a proper input format (4 rows with
** 5 haracters each, followed by a new line or EOF).
** If there is an error with input formatting, return 0.
*/

int		count_tetriminos(char *readout, int row, int column, int i)
{
	while (*readout)
	{
		if (column % 5 == 0 && *readout == '\n')
		{
			row++;
			column = 0;
		}
		else if (column % 5 == 0 && *readout != '\n')
			return (0);
		if (row == 4 && (readout[1] == '\n' || readout[1] == '\0'))
		{
			i++;
			row = 0;
			readout++;
		}
		else if (row == 4 && readout[1] != '\n' && readout[1] != '\0')
			return (0);
		column++;
		readout++;
	}
	if (row != 0)
		return (0);
	return (i);
}

/*
** Save each tetrimino as a bidimensional grid.
** tetrimino[0] = "....\n####\n....\n....\0"
** Each tetrimino has 20 characters (16 characters, 4 newlines and 1 EOF)
*/

char	**split_tetriminos(char *readout)
{
	char	**tetriminos;
	int		len;
	int		i;

	len = count_tetriminos(readout, 0, 1, 0);
	if (!len)
		return (NULL);
	tetriminos = (char **)malloc(sizeof(*tetriminos) * (len + 1));
	if (!tetriminos)
		return (NULL);
	change_readout(readout);
	i = 0;
	while (i < len)
	{
		tetriminos[i] = (char *)malloc(sizeof(**tetriminos) * 20);
		tetriminos[i] = ft_strncpy(tetriminos[i], readout, 19);
		tetriminos[i][19] = '\0';
		if (i + 1 < len)
			readout += 21;
		i++;
	}
	tetriminos[i] = NULL;
	return (tetriminos);
}

/*
** Read the content of the file, process, save and return
** a valid array to work with. Return NULL if it isn't a valid file.
*/

char	*get_input(char *file)
{
	char	buffer[BUFF_SIZE + 1];
	char	*readout;
	int		fd;
	int		read_count;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	readout = ft_strnew(1);
	while ((read_count = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[read_count] = '\0';
		readout = ft_strjoin(readout, buffer);
	}
	close(fd);
	i = -1;
	while (readout[++i])
		if (readout[i] != '.' && readout[i] != '#' && readout[i] != '\n')
			return (NULL);
	if (!ft_val(readout, 0, 0) || !validation(readout))
		return (NULL);
	return (readout);
}
