/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:35:45 by hrings            #+#    #+#             */
/*   Updated: 2022/03/02 13:56:49 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int	ispointinsidewin(t_fdf *fdf, int x, int y);
static void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);

void	bresenham_lower_one(t_fdf *fdf, t_line *line, int sign)
{
	int	dx;
	int	dy;
	int	x;
	int	y;
	int	p;

	dx = line->end->x - line->start->x;
	dy = abs(line->end->y - line->start->y);
	x = line->start->x;
	y = line->start->y;
	p = 2 * dy - dx;
	while (x < line->end->x)
	{
		if (ispointinsidewin(fdf, x, y))
			my_mlx_pixel_put(fdf, x, y, line->color);
		if (p >= 0)
		{
			y += sign;
			p = p + 2 * dy - 2 * dx;
		}
		else
			p = p + 2 * dy;
		x++;
	}
}

void	bresenham_greater_one(t_fdf *fdf, t_line *line, int sign)
{
	int	dx;
	int	dy;
	int	x;
	int	y;
	int	p;

	dx = line->end->x - line->start->x;
	dy = abs(line->end->y - line->start->y);
	x = line->start->x;
	y = line->start->y;
	p = 2 * dx - dy;
	while (y != line->end->y)
	{
		if (ispointinsidewin(fdf, x, y))
			my_mlx_pixel_put(fdf, x, y, line->color);
		if (p >= 0)
		{	
			x++;
			p = p + 2 * dx - 2 * dy;
		}
		else
			p = p + 2 * dx;
		y += sign;
	}
}

static void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	*(unsigned int *)(fdf->addr + (y * fdf->size_line) + x * (fdf->bpp / 8)) \
	= color;
}

static int	ispointinsidewin(t_fdf *fdf, int x, int y)
{
	if (x < 0 || y < 0)
		return (0);
	else if (x >= fdf->width || y >= fdf->height)
		return (0);
	else
		return (1);
}

void	drawbackground(t_fdf *fdf)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < fdf->height)
	{
		while (x < fdf->width)
		{
			my_mlx_pixel_put(fdf, x, y, 0x0);
			x++;
		}
		x = 0;
		y++;
	}
}
