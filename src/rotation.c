/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:31:47 by hrings            #+#    #+#             */
/*   Updated: 2022/02/27 15:45:46 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <math.h>

static void	rotatex(t_fdf *fdf, t_point *point);
static void	rotatey(t_fdf *fdf, t_point *point);
static void	rotatez(t_fdf *fdf, t_point *point);

void	rotate(t_fdf *fdf, t_point *point)
{
	rotatex(fdf, point);
	rotatey(fdf, point);
	rotatez(fdf, point);
}

static void	rotatex(t_fdf *fdf, t_point *point)
{
	int	y;
	int	z;

	y = (int)(point->y * cos(fdf->transform->alpha));
	y -= (int)(point->z * sin(fdf->transform->alpha));
	z = (int)(point->y * sin(fdf->transform->alpha));
	z += (int)(point->z * cos(fdf->transform->alpha));
	point->y = y;
	point->z = z;
}

static void	rotatey(t_fdf *fdf, t_point *point)
{
	int	x;
	int	z;

	x = (int)(point->x * cos(fdf->transform->beta));
	x += (int)(point->z * sin(fdf->transform->beta));
	z = (int)(point->z * cos(fdf->transform->beta));
	z -= (int)(point->x * sin(fdf->transform->beta));
	point->x = x;
	point->z = z;
}

static void	rotatez(t_fdf *fdf, t_point *point)
{
	int	x;
	int	y;

	x = (int)(point->x * cos(fdf->transform->gamma));
	x -= (int)(point->y * sin(fdf->transform->gamma));
	y = (int)(point->x * sin(fdf->transform->gamma));
	y += (int)(point->y * cos(fdf->transform->gamma));
	point->x = x;
	point->y = y;
}
