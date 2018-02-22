/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgorun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 15:42:15 by cgorun            #+#    #+#             */
/*   Updated: 2018/02/11 16:06:43 by cgorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_setcoords(char *str, t_coords *coords, int y, int dotsnr)
{
	int			i;
	int			lastspace;
	int			x;
	static int	pointnb;

	x = -1;
	i = -1;
	lastspace = 1;
	while (str[++i] && pointnb != dotsnr)
	{
		if (ft_isdigit(str[i]) && lastspace == 1)
		{
			coords[pointnb].lastonlinepoint = 0;
			coords[pointnb].x = (++x);
			coords[pointnb].y = y;
			coords[pointnb].dotsnbr = dotsnr;
			coords[pointnb++].z = -(ft_atoi(&str[i]));
			lastspace = 0;
		}
		else
			lastspace = 1;
	}
	coords[pointnb - 1].lastonlinepoint = 1;
}

void	ft_movecoords(t_coords *coords)
{
	int	i;

	i = 0;
	while (i < coords[0].dotsnbr)
	{
		coords[i].x += 500;
		coords[i].y += 500;
		i++;
	}
}

t_line	linestructx(t_coords *coords)
{
	t_line line;

	line.x0 = coords[0].x;
	line.x1 = coords[1].x;
	line.y0 = coords[0].y;
	line.y1 = coords[1].y;
	return (line);
}

t_line	linestructy(t_coords *coords, int points)
{
	t_line line;

	line.x0 = coords[0].x;
	line.x1 = coords[points].x;
	line.y0 = coords[0].y;
	line.y1 = coords[points].y;
	return (line);
}
