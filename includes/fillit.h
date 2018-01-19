/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 14:55:26 by rdavila           #+#    #+#             */
/*   Updated: 2017/02/21 16:32:21 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 20
# include <libft.h>
# include <fcntl.h>
# include <stdlib.h>

typedef	struct	s_point
{
	int		*grid;
	int		*figa;
	int		*figb;
	int		*add;
	int		next;
	char	c;
}				t_point;

/*
** coordinates.c
*/
int				*find_coor(int spot, int row_length);
int				*sum_coor(int *first, int *second);
int				*rest_coor(int *first, int *second);
void			get_coordinates(char *figure, t_point *p, int **coordinates);
int				coor_validator(char **grid, int **coor, int len);

/*
** generators.c
*/
char			**generate_grid(int len);
int				**gen_coor_array(void);
int				*generate_array(int n);
int				*make_array(int x, int y);
int				ft_sqrt(int nb);

/*
** helpers.c
*/
void			fill_grid(char **grid, int **coor, char c);
char			get_char(char *fig);
void			free_grid(char **grid);
void			free_point(t_point *point);
void			change_readout(char *readout);

/*
** input.c
*/
int				ft_val(char *s, int ch, int count);
int				validation(char *s);
int				count_tetriminos(char *readout, int row, int column, int i);
char			**split_tetriminos(char *readout);
char			*get_input(char *tetriminos);

/*
** print.c
*/
void			print_grid(char **grid);
void			print_fig(char **figures);
void			print_order(int *arr, int len);

/*
** solver.c
*/
int				rm_figure(char *figure, char **grid, int row, int column);
int				put_figure(char *figure, char **grid, int *xy, int len);
int				fillit(char **grid, char **figures, int len, int k);
void			solver(char **figures, int num);
#endif
