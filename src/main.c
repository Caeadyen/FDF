/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:26:05 by hrings            #+#    #+#             */
/*   Updated: 2022/03/02 10:28:02 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include "mlx.h"

static void	initfdf(t_fdf *fdf);
static void	initimg(t_fdf *fdf);
static void	controlls(t_fdf *fdf);
static void	cleanup(t_fdf *fdf);

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc == 2)
	{
		fdf = (t_fdf *)malloc(sizeof(t_fdf));
		if (!fdf)
			return (1);
		fdf->filename = argv[1];
		if (readmap(fdf))
		{
			ft_putendl_fd("Loading Map failed", 2);
			free(fdf);
			exit(1);
		}
		fdf->mlx = mlx_init();
		if (!fdf->mlx)
		{
			cleanup(fdf);
			ft_putendl_fd("Mlx failed to initialize", 2);
			exit(1);
		}
		controlls(fdf);
	}
	else
		ft_putendl_fd("Wrong Number of arguments, usage: ./fdf <map>", 2);
}

static void	initimg(t_fdf *fdf)
{
	int		width;
	int		height;
	int		bpp;
	int		size_line;

	width = fdf->width;
	height = fdf->height;
	fdf->mlx_win = mlx_new_window(fdf->mlx, width, height, TITLE);
	fdf->img = mlx_new_image(fdf->mlx, width, height);
	fdf->addr = mlx_get_data_addr(fdf->img, &bpp, &size_line, &fdf->endian);
	fdf->size_line = size_line;
	fdf->bpp = bpp;
}

static void	initfdf(t_fdf *fdf)
{
	t_transform	*transform;

	fdf->height = 1000;
	fdf->width = 1400;
	fdf->offsetx = fdf->width / 2;
	fdf->offsety = ((fdf->height - fdf->column) / 4) + 200;
	fdf->zoom = ((fdf->offsety * 100 / fdf->row) / 10) * 10;
	if (fdf->zoom < 10)
		fdf->zoom = 10;
	transform = (t_transform *)malloc(sizeof(t_transform));
	transform->alpha = 0;
	transform->beta = 0;
	transform->gamma = 0;
	transform->deltax = 0;
	transform->deltay = 0;
	transform->deltaz = 0;
	transform->altitude = 1;
	transform->projection = 0;
	fdf->transform = transform;
	fdf->proj = 5;
	fdf->colorset = 0;
	fdf->numbercolor = 4;
}

static void	controlls(t_fdf *fdf)
{
	initfdf(fdf);
	initimg(fdf);
	drawimg(fdf);
	mlx_hook(fdf->mlx_win, 2, 1L << 0L, key_press, fdf);
	mlx_hook(fdf->mlx_win, 17, 0L, close_win, fdf);
	mlx_loop(fdf->mlx);
}

static void	cleanup(t_fdf *fdf)
{
	int	index;

	index = 0;
	while (index < fdf->row)
	{
		free(fdf->map[index]);
		index++;
	}
	free(fdf->map);
	free(fdf);
}
