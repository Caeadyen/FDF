/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 08:31:42 by hrings            #+#    #+#             */
/*   Updated: 2022/03/02 09:35:35 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	columnlength(char *line)
{
	int	result;

	result = 0;
	while (*line == ' ')
		line++;
	while (*line)
	{
		result++;
		while (*line != ' ' && *line != '\0')
			line++;
		while (*line == ' ' || *line == '\n')
			line++;
	}
	return (result);
}

t_point	*new_point(t_fdf *fdf, int x, int y)
{
	t_point	*point;

	point = (t_point *)malloc(sizeof(t_point));
	if (!point)
		exit(1);
	point->x = x;
	point->y = y;
	point->z = (int)(fdf->map[y][x].z * fdf->transform->altitude);
	point->color = fdf->map[y][x].color;
	return (point);
}

double	ft_abs(double a)
{
	if (a >= 0)
		return (a);
	else
		return (-a);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
