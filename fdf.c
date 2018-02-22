/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgorun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 15:37:49 by cgorun            #+#    #+#             */
/*   Updated: 2018/02/16 18:06:51 by cgorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_image_create(t_mlx *map)
{
	map->image.img_ptr = mlx_new_image(map->mlx_ptr, 3000, 3000);
	map->image.mem = mlx_get_data_addr(map->image.img_ptr,
			&map->image.bpp,
			&map->image.s_line,
			&map->image.endian);
	ft_bzero(map->image.mem, 3000 * 3000);
}

int	ft_fdf(t_coords *coords)
{
	t_mlx	ptr;
	int		deltax;
	int		deltay;

	deltax = 0;
	deltay = 0;
	ft_movecoords(coords);
	ptr.mlx_ptr = mlx_init();
	ptr.win_ptr = mlx_new_window(ptr.mlx_ptr, 3000, 3000, "fdf");
	ptr.size = 20;
	ptr.anglex = 30;
	ptr.angley = 0;
	ptr.anglez = -45;
	ptr.mx = 50;
	ptr.my = 150;
	ptr.r = 1;
	ptr.coords = malloc(sizeof(t_coords) * coords[0].dotsnbr);
	ft_copycoords(ptr.coords, coords);
	fdf_image_create(&ptr);
	draw(coords, &ptr);
	mlx_hook(ptr.win_ptr, 2, 0, key_press, (void *)&ptr);
	mlx_key_hook(ptr.win_ptr, key_hook, (void *)0);
	mlx_loop(ptr.mlx_ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	ft_fdf(ft_read(argv[1]));
}
