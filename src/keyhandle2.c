/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandle2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 09:17:52 by hrings            #+#    #+#             */
/*   Updated: 2022/03/02 10:33:20 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include "keys.h"

static void	change_pers(t_fdf *fdf, int key);
static void	resettransform(t_fdf *fdf);
static void	change_color(t_fdf *fdf, int key);

void	more_key_press(int key, t_fdf *fdf)
{
	if (key == NUM_PAD_DEL || key == NUM_PAD_0)
		change_pers(fdf, key);
	else if (key == NUM_PAD_5)
		resettransform(fdf);
	else if (key == NUM_PAD_MULTI || key == NUM_PAD_DEVIDE)
		change_color(fdf, key);
}

int	close_win(t_fdf *fdf)
{
	int	index;

	mlx_destroy_image(fdf->mlx, fdf->img);
	mlx_destroy_window(fdf->mlx, fdf->mlx_win);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	index = 0;
	while (index < fdf->row)
	{
		free(fdf->map[index]);
		index++;
	}
	free(fdf->map);
	free(fdf->transform);
	free(fdf);
	exit(0);
	return (0);
}

static void	change_pers(t_fdf *fdf, int key)
{
	int	result;

	if (key == NUM_PAD_DEL)
	{
		result = (fdf->transform->projection + fdf->proj - 1) % fdf->proj;
		fdf->transform->projection = result;
	}	
	else if (key == NUM_PAD_0)
	{
		result = (fdf->transform->projection + 1) % fdf->proj;
		fdf->transform->projection = result;
	}	
}

static void	resettransform(t_fdf *fdf)
{
	fdf->transform->alpha = 0;
	fdf->transform->beta = 0;
	fdf->transform->gamma = 0;
	fdf->transform->deltax = 0;
	fdf->transform->deltay = 0;
	fdf->transform->deltaz = 0;
	fdf->transform->altitude = 1;
	fdf->transform->projection = 0;
	fdf->zoom = (fdf->offsety) / fdf->row;
	if (fdf->zoom == 0)
		fdf->zoom = 1;
}

static void	change_color(t_fdf *fdf, int key)
{
	if (key == NUM_PAD_DEVIDE)
		fdf->colorset = (fdf->colorset + 1) % fdf->numbercolor;
	else if (key == NUM_PAD_MULTI)
	{
		fdf->colorset += fdf->numbercolor - 1;
		fdf->colorset = fdf->colorset % fdf->numbercolor;
	}
}
