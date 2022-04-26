/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 08:43:16 by hrings            #+#    #+#             */
/*   Updated: 2022/03/02 10:06:01 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <math.h>

static void	toisometric(t_fdf *fdf, t_point *point);
static void	cabinetview(t_fdf *fdf, t_point *point);
static void	yzview(t_fdf *fdf, t_point *point);
static void	xzview(t_fdf *fdf, t_point *point);

void	projection(t_fdf *fdf, t_point *point)
{
	if (fdf->transform->projection == 0)
		toisometric(fdf, point);
	else if (fdf->transform->projection == 1)
		cabinetview(fdf, point);
	else if (fdf->transform->projection == 2)
		yzview(fdf, point);
	else if (fdf->transform->projection == 3)
		xzview(fdf, point);
	else if (fdf->transform->projection == 4)
		xyview(fdf, point);
}

static void	toisometric(t_fdf *fdf, t_point *point)
{
	float	alpha;
	int		x;
	int		y;

	alpha = atan(0.5);
	x = (int)((point->x - point->y) * cos(alpha));
	x += fdf->offsetx;
	y = (int)((point->x + point->y) * sin(alpha));
	y -= point->z;
	y += fdf->offsety;
	point->x = x;
	point->y = y;
}

static void	cabinetview(t_fdf *fdf, t_point *point)
{
	int	x;
	int	y;

	x = (int)(point->x + 0.25 * -1 * point->y * sqrt(2));
	x += fdf->offsetx;
	y = (int)(point->z + 0.25 * -1 * point->y * sqrt(2));
	y = fdf->height - y;
	y -= fdf->offsety;
	point->x = x;
	point->y = y;
}

static void	yzview(t_fdf *fdf, t_point *point)
{
	point->x = point->y + 200;
	point->y = fdf->offsety - point->z + 200;
}

static void	xzview(t_fdf *fdf, t_point *point)
{
	point->y = fdf->offsety - point->z + 200;
	point->x += 200;
}
