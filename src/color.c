/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 22:24:46 by hrings            #+#    #+#             */
/*   Updated: 2022/03/02 10:17:43 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <math.h>

static void	givencolor(t_line *line);
static void	greenbluecolor(t_fdf *fdf, t_line *line);
static void	bluecolor(t_fdf *fdf, t_line *line);
static void	redcolor(t_fdf *fdf, t_line *line);

void	setcolor(t_fdf *fdf, t_line *line)
{
	if (fdf->colorset == 0)
		givencolor(line);
	else if (fdf->colorset == 1)
		greenbluecolor(fdf, line);
	else if (fdf->colorset == 2)
		bluecolor(fdf, line);
	else if (fdf->colorset == 3)
		redcolor(fdf, line);
}

static void	givencolor(t_line *line)
{
	int	max;
	int	min;

	max = ft_max(line->start->z, line->end->z);
	min = ft_min(line->start->z, line->end->z);
	if (max == 0 && min == 0)
		line->color = line->start->color;
	else if (max > 0)
	{
		if (line->start->z == max)
			line->color = line->start->color;
		else
			line->color = line->end->color;
	}
	else
	{
		if (line->start->z == min)
			line->color = line->start->color;
		else
			line->color = line->end->color;
	}
}

static void	greenbluecolor(t_fdf *fdf, t_line *line)
{
	int		color;
	int		z;
	int		altitude;
	double	zoom;

	zoom = ft_abs(fdf->transform->altitude);
	altitude = fdf->maxz - fdf->minz;
	if (altitude == 0)
		altitude = 1;
	if (line->start->z == 0 && line->end->z == 0)
		line->color = 0xFFFFFF;
	else if (line->start->z > 0 || line->end->z > 0)
	{
		z = ft_max(line->start->z, line->end->z);
		color = (int)((z * 255) / (altitude * zoom));
		line->color = color << 8;
	}
	else
	{
		z = ft_min(line->start->z, line->end->z);
		color = (int)((z * 255) / (altitude * zoom));
		color *= -1;
		line->color = color;
	}
}

static void	redcolor(t_fdf *fdf, t_line *line)
{
	int		color;
	int		z;
	int		altitude;
	double	zoom;

	zoom = ft_abs(fdf->transform->altitude);
	altitude = fdf->maxz - fdf->minz;
	if (altitude == 0)
		altitude = 1;
	if (line->start->z == 0 && line->end->z == 0)
		line->color = 0xFFFFFF;
	else if (line->start->z > 0 || line->end->z > 0)
	{
		z = ft_max(line->start->z, line->end->z);
		color = (int)((z * 255) / (altitude * zoom));
		line->color = color;
	}
	else
	{
		z = ft_min(line->start->z, line->end->z);
		color = (int)((z * 255) / (altitude * zoom));
		line->color = -1 * color;
	}
}

static void	bluecolor(t_fdf *fdf, t_line *line)
{
	int		color;
	int		z;
	int		altitude;
	double	zoom;

	zoom = ft_abs(fdf->transform->altitude);
	altitude = fdf->maxz - fdf->minz;
	if (altitude == 0)
		altitude = 1;
	if (line->start->z == 0 && line->end->z == 0)
		line->color = 0xFFFFFF;
	else if (line->start->z > 0 || line->end->z > 0)
	{
		z = ft_max(line->start->z, line->end->z);
		color = (int)((z * 255) / (altitude * zoom));
		line->color = color << 16;
	}
	else
	{
		z = ft_min(line->start->z, line->end->z);
		color = (int)((z * 255) / (altitude * zoom));
		color *= -1;
		line->color = color << 16;
	}
}
