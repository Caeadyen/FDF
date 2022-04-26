/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 09:26:02 by hrings            #+#    #+#             */
/*   Updated: 2022/03/02 09:05:31 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	translate(t_fdf *fdf, t_point *point);
static void	zoom(t_fdf *fdf, t_point *point);

void	transform(t_fdf *fdf, t_line *line)
{
	zoom(fdf, line->start);
	zoom(fdf, line->end);
	translate(fdf, line->start);
	translate(fdf, line->end);
	rotate(fdf, line->start);
	rotate(fdf, line->end);
	projection(fdf, line->start);
	projection(fdf, line->end);
}

static void	translate(t_fdf *fdf, t_point *point)
{
	point->x += fdf->transform->deltax;
	point->y += fdf->transform->deltay;
	point->z += fdf->transform->deltaz;
}

static void	zoom(t_fdf *fdf, t_point *point)
{
	point->x = (point->x * fdf->zoom) / 100;
	point->y = (point->y * fdf->zoom) / 100;
	point->z = (point->z * fdf->zoom) / 100;
}
