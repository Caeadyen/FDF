/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 09:41:20 by hrings            #+#    #+#             */
/*   Updated: 2022/02/28 15:45:39 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <msg.h>

static void	display_colorset(t_fdf *fdf);
static void	display_projection(t_fdf *fdf);
static void	display_rot_angel(t_fdf *fdf);
static void	display_trans(t_fdf *fdf);

void	drawmenu(t_fdf *fdf)
{
	char	*altitude;
	char	*zoom;

	altitude = ft_itoa((int)(fdf->transform->altitude * 100));
	zoom = ft_itoa((int)(fdf->zoom));
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 25, WHITE, DISPLAY);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 170, 25, WHITE, fdf->filename);
	display_colorset(fdf);
	display_projection(fdf);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 85, WHITE, ALITUDE);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 170, 85, WHITE, altitude);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 200, 85, WHITE, "%");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 105, WHITE, ZOOM);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 170, 105, WHITE, zoom);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 200, 105, WHITE, "%");
	display_rot_angel(fdf);
	display_trans(fdf);
	display_controls(fdf);
	free(altitude);
	free(zoom);
}

static void	display_colorset(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 45, WHITE, COLORSET);
	if (fdf->colorset == 0)
		mlx_string_put(fdf->mlx, fdf->mlx_win, 170, 45, WHITE, PCOLORSET0);
	else if (fdf->colorset == 1)
		mlx_string_put(fdf->mlx, fdf->mlx_win, 170, 45, WHITE, PCOLORSET1);
	else if (fdf->colorset == 2)
		mlx_string_put(fdf->mlx, fdf->mlx_win, 170, 45, WHITE, PCOLORSET2);
	else if (fdf->colorset == 3)
		mlx_string_put(fdf->mlx, fdf->mlx_win, 170, 45, WHITE, PCOLORSET3);
}

static void	display_projection(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 65, WHITE, PROJECTION);
	if (fdf->transform->projection == 0)
		mlx_string_put(fdf->mlx, fdf->mlx_win, 170, 65, WHITE, PROJECTION0);
	else if (fdf->transform->projection == 1)
		mlx_string_put(fdf->mlx, fdf->mlx_win, 170, 65, WHITE, PROJECTION1);
	else if (fdf->transform->projection == 2)
		mlx_string_put(fdf->mlx, fdf->mlx_win, 170, 65, WHITE, PROJECTION2);
	else if (fdf->transform->projection == 3)
		mlx_string_put(fdf->mlx, fdf->mlx_win, 170, 65, WHITE, PROJECTION3);
	else if (fdf->transform->projection == 4)
		mlx_string_put(fdf->mlx, fdf->mlx_win, 170, 65, WHITE, PROJECTION4);
}

static void	display_rot_angel(t_fdf *fdf)
{
	char	*xaxis;
	char	*yaxis;
	char	*zaxis;

	zaxis = ft_itoa((int)(fdf->transform->alpha * 360 / (2 * PI)) % 360);
	xaxis = ft_itoa((int)(fdf->transform->beta * 360 / (2 * PI)) % 360);
	yaxis = ft_itoa((int)(fdf->transform->gamma * 360 / (2 * PI)) % 360);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 125, WHITE, ANGEL);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 170, 125, WHITE, "x-Axis:");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 220, 125, WHITE, xaxis);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 250, 125, WHITE, "Deg, y-Axis:");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 325, 125, WHITE, yaxis);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 350, 125, WHITE, "Deg, z-Axis:");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 425, 125, WHITE, zaxis);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 450, 125, WHITE, "Deg");
	free(xaxis);
	free(yaxis);
	free(zaxis);
}

static void	display_trans(t_fdf *fdf)
{
	char	*deltax;
	char	*deltay;
	char	*deltaz;

	deltax = ft_itoa(fdf->transform->deltax);
	deltay = ft_itoa(-1 * fdf->transform->deltay);
	deltaz = ft_itoa(fdf->transform->deltaz);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 145, WHITE, TRANS);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 170, 145, WHITE, "x-Direction:");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 250, 145, WHITE, deltax);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 280, 145, WHITE, "y-Direction:");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 360, 145, WHITE, deltay);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 390, 145, WHITE, "z-Direction:");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 470, 145, WHITE, deltaz);
	free(deltax);
	free(deltay);
	free(deltaz);
}
