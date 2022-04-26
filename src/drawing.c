/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 22:13:59 by hrings            #+#    #+#             */
/*   Updated: 2022/03/02 14:05:16 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <math.h>

static void	drawline(t_fdf *fdf, t_line *line);
static int	setright(t_fdf *fdf, t_line *line, int x, int y);
static int	setdown(t_fdf *fdf, t_line *line, int x, int y);
static void	checkline(t_line *line);

void	drawimg(t_fdf *fdf)
{
	t_line	*line;
	int		x;
	int		y;

	drawbackground(fdf);
	line = (t_line *)malloc(sizeof(t_line));
	x = 0;
	y = 0;
	while (y < fdf->row)
	{
		while (x < fdf->column)
		{
			if (setright(fdf, line, x, y))
				drawline(fdf, line);
			if (setdown(fdf, line, x, y))
				drawline(fdf, line);
			x++;
		}
		x = 0;
		y++;
	}
	free(line);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img, 0, 0);
	drawmenu(fdf);
}

static void	drawline(t_fdf *fdf, t_line *line)
{
	int		dx;
	int		dy;
	float	slope;

	checkline(line);
	dx = line->end->x - line->start->x;
	dy = line->end->y - line->start->y;
	if (dx == 0)
		slope = dy * 10;
	else
		slope = (float) dy / dx;
	if ((slope >= 0) && (slope <= 1))
		bresenham_lower_one(fdf, line, 1);
	else if ((slope >= -1) && (slope < 0))
		bresenham_lower_one(fdf, line, -1);
	else if (slope > 1)
		bresenham_greater_one(fdf, line, 1);
	else if (slope < -1)
		bresenham_greater_one(fdf, line, -1);
	free(line->start);
	free(line->end);
}

static int	setright(t_fdf *fdf, t_line *line, int x, int y)
{
	if (x < fdf->column - 1)
	{
		line->start = new_point(fdf, x, y);
		line->end = new_point(fdf, x + 1, y);
		setcolor(fdf, line);
		transform(fdf, line);
		return (1);
	}
	else
		return (0);
}

static int	setdown(t_fdf *fdf, t_line *line, int x, int y)
{
	if (y < fdf->row - 1)
	{
		line->start = new_point(fdf, x, y);
		line->end = new_point(fdf, x, y + 1);
		setcolor(fdf, line);
		transform(fdf, line);
		return (1);
	}
	else
		return (0);
}

static void	checkline(t_line *line)
{
	int	tmpx;
	int	tmpy;

	if (line->start->x > line->end->x)
	{
		tmpx = line->end->x;
		tmpy = line->end->y;
		line->end->x = line->start->x;
		line->end->y = line->start->y;
		line->start->x = tmpx;
		line->start->y = tmpy;
	}
}
