/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 10:08:50 by hrings            #+#    #+#             */
/*   Updated: 2022/03/02 10:18:04 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <mlx.h>
# include <stdio.h>
# include <libft.h>

# define TITLE "FDF Project by hrings"

typedef struct s_altitude
{
	int	z;
	int	color;
}		t_altitude;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}		t_point;

typedef struct s_transform
{
	double	alpha;
	double	beta;
	double	gamma;
	int		deltax;
	int		deltay;
	int		deltaz;
	double	altitude;
	int		projection;
}		t_transform;

typedef struct s_fdf
{
	char		*filename;
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bpp;
	int			size_line;
	int			endian;
	t_altitude	**map;
	int			row;
	int			column;
	int			zoom;
	int			height;
	int			width;
	int			offsetx;
	int			offsety;
	t_transform	*transform;
	int			proj;
	int			colorset;
	int			numbercolor;
	int			maxz;
	int			minz;
}				t_fdf;

typedef struct s_line
{
	t_point	*start;
	t_point	*end;
	int		color;
}			t_line;

int		close_win(t_fdf *fdf);
int		columnlength(char *line);
int		key_press(int key, t_fdf *fdf);
void	more_key_press(int key, t_fdf *fdf);
int		readmap(t_fdf *fdf);
t_list	*readfile(t_fdf *fdf, const int fd);
void	buildmap(t_fdf *fdf, t_list *head);
void	drawimg(t_fdf *fdf);
void	projection(t_fdf *fdf, t_point *point);
void	bresenham_greater_one(t_fdf *fdf, t_line *line, int sign);
void	bresenham_lower_one(t_fdf *fdf, t_line *line, int sign);
void	transform(t_fdf *fdf, t_line *line);
void	drawbackground(t_fdf *fdf);
void	rotate(t_fdf *fdf, t_point *point);
t_point	*new_point(t_fdf *fdf, int x, int y);
void	setcolor(t_fdf *fdf, t_line *line);
double	ft_abs(double a);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
void	drawmenu(t_fdf *fdf);
void	display_controls(t_fdf *fdf);
void	xyview(t_fdf *fdf, t_point *point);
#endif