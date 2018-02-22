/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgorun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 18:38:42 by cgorun            #+#    #+#             */
/*   Updated: 2018/02/16 17:52:46 by cgorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define DX 0
#define DY 1
#define YI 2
#define D 3
#define Y 4
#define X 5
#define XI 2

void	putlinelow(t_line *line, t_mlx *ptr, int color)
{
	int	aux[6];

	aux[DX] = line->x1 - line->x0;
	aux[DY] = line->y1 - line->y0;
	aux[YI] = 1;
	if (aux[DY] < 0)
	{
		aux[YI] = -1;
		aux[DY] = -aux[DY];
	}
	aux[D] = 2 * aux[DY] - aux[DX];
	aux[Y] = line->y0;
	aux[X] = line->x0;
	while (aux[X] < line->x1)
	{
		if (aux[X] >= 0 && aux[X] < 3000 && aux[Y] < 3000 && aux[Y] >= 0)
			*(int *)((ptr->image.mem + ((aux[X] + aux[Y] * 3000) * 4))) = color;
		if (aux[D] > 0)
		{
			aux[Y] = aux[Y] + aux[YI];
			aux[D] = aux[D] - 2 * aux[DX];
		}
		aux[D] = aux[D] + 2 * aux[DY];
		aux[X]++;
	}
}

void	putlinehigh(t_line *line, t_mlx *ptr, int color)
{
	int	aux[6];

	aux[DX] = line->x1 - line->x0;
	aux[DY] = line->y1 - line->y0;
	aux[XI] = 1;
	if (aux[DX] < 0)
	{
		aux[XI] = -1;
		aux[DX] = -aux[DX];
	}
	aux[D] = 2 * aux[DX] - aux[DY];
	aux[Y] = line->y0;
	aux[X] = line->x0;
	while (aux[Y] < line->y1)
	{
		if (aux[X] >= 0 && aux[X] < 3000 && aux[Y] < 3000 && aux[Y] >= 0)
			*(int *)((ptr->image.mem + ((aux[X] + aux[Y] * 3000) * 4))) = color;
		if (aux[D] > 0)
		{
			aux[X] = aux[X] + aux[XI];
			aux[D] = aux[D] - 2 * aux[DY];
		}
		aux[D] = aux[D] + 2 * aux[DX];
		aux[Y]++;
	}
}

void	ft_swap(t_line *line)
{
	int	x;
	int	y;

	x = line->x0;
	y = line->y0;
	line->x0 = line->x1;
	line->y0 = line->y1;
	line->x1 = x;
	line->y1 = y;
}

void	putline(t_line line, t_mlx *ptr, int color)
{
	if (abs(line.y1 - line.y0) < abs(line.x1 - line.x0))
	{
		if (line.x0 > line.x1)
		{
			ft_swap(&line);
			putlinelow(&line, ptr, color);
			ft_swap(&line);
		}
		else
			putlinelow(&line, ptr, color);
	}
	else if (line.y0 > line.y1)
	{
		ft_swap(&line);
		putlinehigh(&line, ptr, color);
		ft_swap(&line);
	}
	else
		putlinehigh(&line, ptr, color);
}
