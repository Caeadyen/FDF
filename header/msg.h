/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 09:42:42 by hrings            #+#    #+#             */
/*   Updated: 2022/02/28 12:25:56 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSG_H
# define MSG_H

# define WHITE 0xFFFFFF
# define PI 3.14159265359
# define DISPLAY "Map that is shown:"
# define COLORSET "Current color set:"
# define PCOLORSET0 "colors given in the map, yellow if none given"
# define PCOLORSET1 "green positive z, blue negative z"
# define PCOLORSET2 "none zero z is red"
# define PCOLORSET3 "none zero z is blue"
# define PROJECTION "Current Projection:"
# define PROJECTION0 "Isomatric"
# define PROJECTION1 "Cabinet"
# define PROJECTION2 "Sideview onto yz-Plane"
# define PROJECTION3 "Sideview onto xz-Plane"
# define PROJECTION4 "Topview"
# define ALITUDE "Alitude displayed with:"
# define ZOOM "Zoom level is:"
# define ANGEL "Rotation of the Map:"
# define TRANS "Displacement of the Map:"
# define CONTROLS "Controls, reset with Numpad 5:"
# define XMOVE "Move in x direction: minus[a] and plus[d]"
# define YMOVE "Move in y direction: minus[s] and plus[w]"
# define ZMOVE "Move in z direction: minus[q] and plus[e]"
# define ZZOOM "Zoom: Increase [+] and decrease [-]"
# define AZOOM "Altitude zoom: Increase [NUM 9] and decrease [NUM 3]"
# define XROT "Rotate around the x axis: plus[NUM 2] and minus[NUM 8]"
# define YROT "Rotate around the y axis: plus[NUM 4] and minus[NUM 6]"
# define ZROT "Rotate around the z axis: plus[NUM 7] and minus[NUM 1]"
# define COLOR "Switch through colorset with [NUM /] and [NUM *]"
# define PROJ "Switch through Projections with [NUM 0] and [NUM ,]"
#endif