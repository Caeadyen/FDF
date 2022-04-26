/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 10:22:49 by hrings            #+#    #+#             */
/*   Updated: 2022/02/28 15:44:20 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keys.h"

static void	change_pos(t_fdf *fdf, int key);
static void	change_rot(t_fdf *fdf, int key);
static void	change_altitude(t_fdf *fdf, int key);
static void	change_zoom(t_fdf *fdf, int key);

int	key_press(int key, t_fdf *fdf)
{
	if (key == ESC)
		close_win(fdf);
	else if (key == A_KEY || key == D_KEY || key == S_KEY || key == W_KEY)
		change_pos(fdf, key);
	else if (key == Q_KEY || key == E_KEY)
		change_pos(fdf, key);
	else if (key == NUM_PAD_2 || key == NUM_PAD_4)
		change_rot(fdf, key);
	else if (key == NUM_PAD_6 || key == NUM_PAD_8)
		change_rot(fdf, key);
	else if (key == NUM_PAD_1 || key == NUM_PAD_7)
		change_rot(fdf, key);
	else if (key == NUM_PAD_9 || key == NUM_PAD_3)
		change_altitude(fdf, key);
	else if (key == NUM_PAD_PLUS || key == NUM_PAD_MINUS)
		change_zoom(fdf, key);
	else
		more_key_press(key, fdf);
	drawimg(fdf);
	return (0);
}

static void	change_pos(t_fdf *fdf, int key)
{
	if (key == A_KEY)
		fdf->transform->deltax -= 10;
	else if (key == D_KEY)
		fdf->transform->deltax += 10;
	else if (key == W_KEY)
		fdf->transform->deltay -= 10;
	else if (key == S_KEY)
		fdf->transform->deltay += 10;
	else if (key == Q_KEY)
		fdf->transform->deltaz += 10;
	else if (key == E_KEY)
		fdf->transform->deltaz -= 10;
}

static void	change_rot(t_fdf *fdf, int key)
{
	if (key == NUM_PAD_2)
		fdf->transform->alpha += 0.05;
	else if (key == NUM_PAD_8)
		fdf->transform->alpha -= 0.05;
	else if (key == NUM_PAD_4)
		fdf->transform->beta += 0.05;
	else if (key == NUM_PAD_6)
		fdf->transform->beta -= 0.05;
	else if (key == NUM_PAD_1)
		fdf->transform->gamma += 0.05;
	else if (key == NUM_PAD_7)
		fdf->transform->gamma -= 0.05;
}

static void	change_altitude(t_fdf *fdf, int key)
{
	if (key == NUM_PAD_9)
		fdf->transform->altitude += 0.1;
	else if (key == NUM_PAD_3)
		fdf->transform->altitude -= 0.1;
}

static void	change_zoom(t_fdf *fdf, int key)
{
	if (key == NUM_PAD_PLUS)
		fdf->zoom += 10;
	else if (key == NUM_PAD_MINUS)
		fdf->zoom -= 10;
}
