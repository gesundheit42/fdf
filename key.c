/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgorun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 15:38:43 by cgorun            #+#    #+#             */
/*   Updated: 2018/02/11 16:15:31 by cgorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_pressv2(int keycode, t_mlx *mlx)
{
	if (keycode == 13)
		mlx->anglex = mlx->anglex + 2;
	else if (keycode == 1)
		mlx->anglex = mlx->anglex - 2;
	else if (keycode == 0)
		mlx->angley = mlx->angley - 2;
	else if (keycode == 2)
		mlx->angley = mlx->angley + 2;
	else if (keycode == 126)
		mlx->my += 5;
	else if (keycode == 125)
		mlx->my -= 5;
	else if (keycode == 14)
		mlx->anglez -= 2;
	else if (keycode == 12)
		mlx->anglez += 2;
	else if (keycode == 24)
		mlx->size = mlx->size + 1;
	else if (keycode == 27)
		mlx->size = mlx->size - 1;
	else if (keycode == 124)
		mlx->mx -= 5;
	else if (keycode == 123)
		mlx->mx += 5;
}

int		key_press(int keycode, t_mlx *mlx)
{
	t_mlx	ptr;

	ptr.coords = malloc(sizeof(t_coords) * mlx->coords[0].dotsnbr);
	ft_copycoords(ptr.coords, mlx->coords);
	key_pressv2(keycode, mlx);
	mlx->anglex = mlx->anglex % 360;
	mlx->angley = mlx->angley % 360;
	mlx->anglez = mlx->anglez % 360;
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	draw(ptr.coords, mlx);
	free(ptr.coords);
	return (0);
}

int		key_hook(int keycode, void *param)
{
	(void)param;
	if (keycode == 53)
		exit(3);
	return (0);
}
