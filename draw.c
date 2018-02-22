/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgorun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 15:40:13 by cgorun            #+#    #+#             */
/*   Updated: 2018/02/16 18:08:26 by cgorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define A 0
#define B 1
#define Z 2

void	changeprojection(t_coords *coords, t_mlx *mlx)
{
	int		i;
	float	d[3];
	int		yy;
	int		xx;
	int		zz;

	d[A] = 3.14 / 180 * mlx->anglex;
	d[B] = 3.14 / 180 * mlx->angley;
	d[Z] = 3.14 / 180 * mlx->anglez;
	i = 0;
	while (i < coords[0].dotsnbr)
	{
		xx = coords[i].x * mlx->size;
		zz = coords[i].z * mlx->size / 9;
		yy = coords[i].y * mlx->size;
		coords[i].x = cos(d[B]) * (sin(d[Z]) * yy + cos(d[Z]) * xx) -
		sin(d[B]) * zz + mlx->mx;
		coords[i].y = sin(d[A]) * (cos(d[B]) *
		zz + sin(d[B]) * (sin(d[Z]) * yy +
		cos(d[Z]) * xx)) + cos(d[A]) *
		(cos(d[Z]) * yy - sin(d[Z]) * xx) + mlx->my;
		i++;
	}
}

void	draw(t_coords *coords, t_mlx *ptr)
{
	int	i;
	int	onlinepoints;
	int	d;
	int	delta[2];

	ft_to00(coords, &delta[0], &delta[1]);
	changeprojection(coords, ptr);
	ft_toorigin(coords, delta[0], delta[1]);
	i = 0;
	onlinepoints = ft_onlinepoints(coords);
	d = coords[0].dotsnbr - onlinepoints;
	while (i < coords[0].dotsnbr)
	{
		if (coords[i].lastonlinepoint == 0)
			putline(linestructx(&coords[i]), ptr, 0x00ff00);
		if (i < d)
			putline(linestructy(&coords[i], onlinepoints), ptr, 0x00ff00);
		i++;
	}
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->image.img_ptr, 0, 0);
}

void	ft_to00(t_coords *coords, int *deltax, int *deltay)
{
	int	i;
	int	origin;

	origin = coords[0].dotsnbr / 2;
	i = 0;
	*deltax = coords[origin].x;
	*deltay = coords[origin].y;
	while (i < coords[0].dotsnbr)
	{
		coords[i].x = coords[i].x - *deltax;
		coords[i].y = coords[i].y - *deltay;
		i++;
	}
}

void	ft_toorigin(t_coords *coords, int deltax, int deltay)
{
	int	i;

	i = 0;
	while (i < coords[0].dotsnbr)
	{
		coords[i].x = coords[i].x + deltax;
		coords[i].y = coords[i].y + deltay;
		i++;
	}
}
