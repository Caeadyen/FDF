/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:06:41 by hrings            #+#    #+#             */
/*   Updated: 2022/02/28 12:22:53 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <msg.h>

void	display_controls(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->mlx_win, 550, 25, WHITE, CONTROLS);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 550, 45, WHITE, "Translation:");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 550, 65, WHITE, XMOVE);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 550, 85, WHITE, YMOVE);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 550, 105, WHITE, ZMOVE);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 550, 125, WHITE, ZZOOM);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 550, 145, WHITE, AZOOM);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 900, 45, WHITE, "Rotation:");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 900, 65, WHITE, XROT);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 900, 85, WHITE, YROT);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 900, 105, WHITE, ZROT);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 900, 125, WHITE, COLOR);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 900, 145, WHITE, PROJ);
}
